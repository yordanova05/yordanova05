function data(){
    const seconds = document.getElementById("seconds").value;
    const name = document.getElementById("filtername").value;
    const sort = document.getElementById("sorted").value;
    const order = document.getElementById("order").value;
    const ppid = document.getElementById("ppid").value;

    const url = `/process?seconds=${seconds}&name=${name}&sort=${sort}&order=${order}&ppid=${ppid}`

    fetch(url)
        .then(response => response.json())
        .then(data => {
            const tbody = document.getElementById("table-body");
            tbody.innerHTML = ""; // Изчистване на предишни редове

            data.forEach(p => {
                const row = document.createElement("tr");
                row.innerHTML = `
                    <td>${p.pid}</td>
                    <td>${p.name}</td>
                    <td>${p.cpu_percent}</td>
                    <td>${p.memory_percent}</td>
                    <td>${p.status}</td>
                    <td>${p.ppid}</td>
                `;
                tbody.appendChild(row);
            });
        });

    if ( seconds > 0 ){
        refreshTimeout = setTimeout(data, seconds * 1000);
    }
}

function clear_all(){
    document.getElementById("seconds").value = "";
    document.getElementById("filtername").value = "";
    document.getElementById("sorted").value = "pid";
    document.getElementById("order").value = "asc";
    document.getElementById("ppid").value = "";

    document.getElementById("table-body").innerHTML = "";
        if (refreshTimeout){
            clearTimeout(refreshTimeout);
            refreshTimeout = null;
        }
}

window.onload = () => {
    isClear = false;
    document.getElementById("result").addEventListener("click", data)

    document.getElementById("clear").addEventListener("click",clear_all)
}