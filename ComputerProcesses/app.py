from flask import Flask, request, jsonify, render_template
import psutil as psu

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/process")
def process_status(filter_name = None, sort_by = None, order = "asc", ppid = None):
    
    filter_name = request.args.get("name",default=None,type=str)
    sort_by = request.args.get("sort", default=None, type=str)
    order = request.args.get("order", default="asc", type=str)
    ppid = request.args.get("ppid", default=None, type= int)
    
    process_list = []
    process_settings = ["pid","name","cpu_percent","memory_percent","status","ppid"]
    anomalies = []
    cpu_max = 85.0
    memory_max = 80.0
    
    for p in psu.process_iter(process_settings):
        try:
            info = p.info
            
            if info["name"] == "System Idle Process" or info["pid"] == 0:
                continue
        
            if filter_name and filter_name.lower() not in info["name"].lower():
                continue
            
            if ppid and info["ppid"] != ppid:
                continue
            
            if info["cpu_percent"] >= cpu_max or info["memory_percent"] >= memory_max:
                
                anomalies.append(p.name())
            
            process_list.append(info)
                
        except(psu.NoSuchProcess, psu.AccessDenied):
            continue
        
    
    if sort_by in info:
        if order.lower() == "desc":
            process_list.sort(key = lambda x: x[sort_by], reverse = True)
        elif order.lower() == "asc":
            process_list.sort(key = lambda x: x[sort_by], reverse = False)
        
    return jsonify(process_list, anomalies)

if __name__ == "__main__":
    
    app.run(debug=True)