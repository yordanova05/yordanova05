let refreshTimeout = null;
function data_analyze(){

    const seconds = document.getElementById("seconds").value;
    const name = document.getElementById("filtername").value;
    const sort = document.getElementById("sorted").value;
    const order = document.getElementById("order").value;
    const ppid = document.getElementById("ppid").value;

    const url = `/process?name=${name}&sort=${sort}&order=${order}&ppid=${ppid}`

    fetch(url)
        .then(response => response.json())
        .then(data => {
            const tbody = document.getElementById("table-body");
            tbody.innerHTML = ""; // Изчистване на предишни редове

            if ( data.processes ){
                    data.processes.forEach(p => {
                    const row = document.createElement("tr");
                    row.innerHTML = `
                        <td>${p.pid}</td>
                        <td>${p.name}</td>
                        <td>${p.cpu_percent}</td>
                        <td>${p.memory_percent}</td>
                        <td>${p.status}</td>
                        <td>${p.ppid}</td>
                    `;
                    if (data.anomalies.includes(p.pid)){
                        row.classList.add("anomal-class");
                    }
                    tbody.appendChild(row);
                });
                if ( seconds > 0 ){
                    refreshTimeout = setTimeout(data_analyze, seconds * 1000);
                } 
            }
            else{
                const message = document.createElement("h3");
                message.innerHTML = data.message
                message.classList.add("no-data-message");
                document.body.appendChild(message);
                return;
            }
        });
        
    
}

function clear_all(){
    document.getElementById("seconds").value = "";
    document.getElementById("filtername").value = "";
    document.getElementById("sorted").value = "pid";
    document.getElementById("order").value = "asc";
    document.getElementById("ppid").value = "";

    const message = document.querySelector(".no-data-message");
    if (message) {
        message.remove();
    }

    if (refreshTimeout){
        clearTimeout(refreshTimeout);
        refreshTimeout = null;
    }
    document.getElementById("table-body").innerHTML = "";
        
}

window.onload = () => {
    document.getElementById("result").addEventListener("click", data_analyze)
    document.getElementById("clear").addEventListener("click",clear_all)
}