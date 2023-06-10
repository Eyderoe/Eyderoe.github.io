function showTime() {
    let date = new Date();
    let hours = date.getUTCHours();
    let minutes = date.getUTCMinutes();
    let seconds = date.getUTCSeconds();
    let year = date.getFullYear();
    let month = date.getMonth();
    month += 1;
    let day = date.getDate();

    document.getElementById('time').innerHTML = "&nbsp;&nbsp;UTC:&nbsp;" + hours + ":" + minutes + ":" + ((seconds < 10) ? "0" : "") + seconds;
    document.getElementById('dating').innerHTML = "&nbsp;&nbsp;" + year + "年" + month + "月" + day + "日";
}

/*
* */

setInterval(showTime, 1000)
