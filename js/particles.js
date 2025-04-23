!function () {
    function getAttributeValue(element, attributeName, defaultValue) {
        return element.getAttribute(attributeName) || defaultValue;
    }

    function getElementsByTagName(tagName) {
        return document.getElementsByTagName(tagName);
    }

    function getScriptConfig() {
        var scripts = getElementsByTagName("script"),
            scriptCount = scripts.length,
            currentScript = scripts[scriptCount - 1];

        return {
            scriptCount: scriptCount,
            zIndex: getAttributeValue(currentScript, "zIndex", -1),
            opacity: getAttributeValue(currentScript, "opacity", .5),

            color: getAttributeValue(currentScript, "color", "52, 211, 153"),
            particleCount: getAttributeValue(currentScript, "count", 120)
        };
    }

    function updateCanvasSize() {
        canvasWidth = canvas.width = window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth,
            canvasHeight = canvas.height = window.innerHeight || document.documentElement.clientHeight || document.body.clientHeight;
    }

    function drawParticles() {
        context.clearRect(0, 0, canvasWidth, canvasHeight);

        var particleA, particleB, distance, dx, dy, maxDistance, alpha;
        particles.forEach(function (particleA, index) {
            particleA.x += particleA.xVelocity;
            particleA.y += particleA.yVelocity;
            particleA.xVelocity *= particleA.x > canvasWidth || particleA.x < 0 ? -1 : 1;
            particleA.yVelocity *= particleA.y > canvasHeight || particleA.y < 0 ? -1 : 1;
            context.fillRect(particleA.x - .5, particleA.y - .5, 1, 1);

            for (var j = index + 1; j < allParticles.length; j++) {
                particleB = allParticles[j];
                if (particleB.x !== null && particleB.y !== null) {
                    dx = particleA.x - particleB.x;
                    dy = particleA.y - particleB.y;
                    distance = dx * dx + dy * dy;
                    if (distance < particleB.maxDistance) {
                        // if (particleB === mouseParticle && distance >= particleB.maxDistance / 2) { // 鼠标拖拽代码
                        //     particleA.x -= .01 * dx;
                        //     particleA.y -= .01 * dy;
                        // }
                        alpha = (particleB.maxDistance - distance) / particleB.maxDistance;
                        context.beginPath();
                        context.lineWidth = alpha / 2;
                        context.strokeStyle = "rgba(" + scriptConfig.color + "," + (alpha + .2) + ")";
                        context.moveTo(particleA.x, particleA.y);
                        context.lineTo(particleB.x, particleB.y);
                        context.stroke();
                    }
                }
            }
        });

        requestAnimationFrame(drawParticles);
    }

    var canvasWidth, canvasHeight, allParticles, canvas = document.createElement("canvas"),
        scriptConfig = getScriptConfig(), context = canvas.getContext("2d"),
        requestAnimationFrame = window.requestAnimationFrame ||
            function (callback) {
                window.setTimeout(callback, 1000 / 45);
            },
        random = Math.random, mouseParticle = {x: null, y: null, maxDistance: 20000};

    canvas.id = "c_n" + scriptConfig.scriptCount;
    canvas.style.cssText = "position:fixed;top:0;left:0;z-index:" + scriptConfig.zIndex + ";opacity:" + scriptConfig.opacity;
    getElementsByTagName("body")[0].appendChild(canvas);
    updateCanvasSize();
    window.onresize = updateCanvasSize;

    window.onmousemove = function (event) {
        event = event || window.event;
        mouseParticle.x = event.clientX;
        mouseParticle.y = event.clientY;
    };

    window.onmouseout = function () {
        mouseParticle.x = null;
        mouseParticle.y = null;
    };

    var particles = [];
    for (var i = 0; i < scriptConfig.particleCount; i++) {
        var xPos = random() * canvasWidth,
            yPos = random() * canvasHeight,
            xVelocity = 2 * random() - 1,
            yVelocity = 2 * random() - 1;
        xVelocity *= 0.4;
        yVelocity *= 0.4;
        particles.push({x: xPos, y: yPos, xVelocity: xVelocity, yVelocity: yVelocity, maxDistance: 6000});
    }

    allParticles = particles.concat([mouseParticle]);

    setTimeout(function () {
        drawParticles();
    }, 100);

}();
