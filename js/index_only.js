function showTime() {
    let date = new Date();
    let hours = date.getHours();
    let minutes = date.getMinutes();
    let seconds = date.getSeconds();
    let year = date.getFullYear();
    let month = date.getMonth();
    month+=1;
    let day = date.getDate();

    hours = formatTime(hours);
    minutes = formatTime(minutes);
    seconds = formatTime(seconds);

    document.getElementById('time').innerHTML = "&nbsp;&nbsp;BPM发波台:&nbsp;" + hours + ":" + minutes + ":" + seconds;
    document.getElementById('dating').innerHTML = "&nbsp;&nbsp;" + year + "年" + month + "月" + day + "日";
}

function formatTime(time) {
    if (time < 10) {
        time = "0" + time;
    }
    return time;
}

setInterval(showTime, 1000)