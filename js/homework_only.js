var currentAudio = null;

function playAudio(name) {
    var audio;
    audio = document.getElementById(name);
    if (currentAudio !== audio && (currentAudio != null)) {
        currentAudio.pause();
    }
    audio.play();
    currentAudio = audio;
}

function stopAudio(name) {
    var audio_;
    audio_ = document.getElementById(name);
    if (currentAudio === audio_) {
        currentAudio.pause();
    }
}

function reAudio(name) {
    var audio__;
    audio__ = document.getElementById(name);
    if (audio__ === currentAudio) {
        currentAudio.currentTime = 0;
    }
}

function changeColor(){
    const randomColor = Math.floor(Math.random()*16777215).toString(16)
    document.querySelector('#rubbish').style.backgroundColor="#"+randomColor;
}

setInterval(changeColor,1000)