from flask import Flask, request, render_template
import psutil as psu
import time

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/process")
def process_status(filter_name = None, sort_by = None, order = "asc", parentid = None):
    process_list = []
    process_settings = ["pid","name","cpu_percent","memory_percent","status","ppid"]
    anomalies = []
    cpu_max = 85.0
    memory_max = 80.0
    
    for p in psu.process_iter(process_settings):
        try:
            info = p.info
            
            p.cpu_percent(interval=0.1)
        
            if filter_name and filter_name.lower() not in info["name"].lower():
                continue
            
            if parentid and info["ppid"] != parentid:
                continue
            
            if p.info["cpu_percent"] >= cpu_max or p.info["memory_percent"] >= memory_max:
                
                anomalies.append(p.name())
            
            process_list.append(info)
                
        except(psu.NoSuchProcess, psu.AccessDenied):
            continue
        
    sort_by = sort_by.lower()
    
    if sort_by in info:
        if order.lower() == "desc":
            process_list.sort(key = lambda x: x[sort_by], reverse = True)
        elif order.lower() == "asc":
            process_list.sort(key = lambda x: x[sort_by], reverse = False)
            
    if anomalies:
        for anom in anomalies:
            print(f"{anom} use too much memory!")
        
    return render_template("index.html", data=process_list)
            

if __name__ == "__main__":
    
    app.run(debug=True)
    
    x = float(input("Second: "))
    
    while True:
        process = process_status(sort_by="cpu_percent", order="asc")
        
        for p in process:
            print(p)
        print("-" * 40)
        
        time.sleep(x)