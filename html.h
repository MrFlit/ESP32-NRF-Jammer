const char* html = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
            opacity: 0;
            animation: fadeIn 1s forwards;
        }

        @keyframes fadeIn {
            from {
                opacity: 0;
            }
            to {
                opacity: 1;
            }
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: 1c1c1c;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
            transform: translateY(20px);
            animation: slideIn 0.5s forwards;
        }

        @keyframes slideIn {
            from {
                transform: translateY(20px);
                opacity: 0;
            }
            to {
                transform: translateY(0);
                opacity: 1;
            }
        }

        .header {
            margin-bottom: 20px;
            animation: logoMovement 1s infinite alternate;
        }

        @keyframes logoMovement {
            0% { transform: translateY(0); }
            100% { transform: translateY(-5px); }
        }

        .header img {
            width: 100px; 
            height: auto;
            margin-bottom: 10px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button, .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover, .dropdown-button:hover {
            background-color: #4201bc; 
            transform: translateY(-4px) scale(1.05); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active, .dropdown-button:active {
            transform: translateY(2px); 
        }

        .button:focus, .dropdown-button:focus {
            outline: none; 
        }

        .settings-button {
            background-color: #2ae168;
        }
		
        .settings-button:hover {
            background-color:rgb(27, 143, 65); 
            transform: translateY(-4px) scale(1.05); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .ota-button {
            background-color: #ffba00; 
        }
		
        .ota-button:hover {
            background-color:rgb(170, 125, 0); 
            transform: translateY(-4px) scale(1.05); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.9);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown.show {
            display: flex;
            animation: dropdownExpand 0.6s forwards;
        }

        @keyframes dropdownExpand {
            0% {
                opacity: 0;
                transform: scaleY(0);
            }
        }

        .hidden {
            opacity: 0;
            transform: translateY(-20px);
            transition: opacity 0.2s ease, transform 0.2s ease;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.classList.toggle('show');

            const items = dropdown.querySelectorAll('.dropdown-button');

            if (dropdown.classList.contains('show')) {
                items.forEach((item, index) => {
                    setTimeout(() => {
                        item.classList.remove('hidden');
                        item.style.opacity = 1;
                        item.style.transform = 'translateY(0)';
                    }, index * 50);
                });
            } else {
                items.forEach((item) => {
                    item.classList.add('hidden');
                    item.style.opacity = 0;
                    item.style.transform = 'translateY(-20px)';
                });
            }
        }

        window.addEventListener('click', function(event) {
            const dropdown = document.getElementById('settingsDropdown');
            const settingsButton = document.querySelector('.settings-button');
            if (!settingsButton.contains(event.target) && !dropdown.contains(event.target)) {
                dropdown.classList.remove('show');
                const items = dropdown.querySelectorAll('.dropdown-button');
                items.forEach((item) => {
                    item.classList.add('hidden');
                    item.style.opacity = 0;
                    item.style.transform = 'translateY(-20px)';
                });
            }
        });
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <img src="../logo/hs.png" alt="Logo"></img>
        </div>

        <div class="buttons">
            <button onclick="location.href='/bluetooth_jam'" class="button">Bluetooth jammer</button>
            <button onclick="location.href='/drone_jam'" class="button">Drone jammer</button>
            <button onclick="location.href='/wifi_select'" class="button">WiFi jammer</button>
            <button onclick="location.href='/ble_jam'" class="button">BLE jammer</button>
            <button onclick="location.href='/zigbee_jam'" class="button">Zigbee jammer</button>
            <button onclick="location.href='/misc_jammer'" class="button">Misc jammer</button>
            <button class="button settings-button" onclick="toggleDropdown()">Настройки</button>
            <button onclick="location.href='/OTA'" class="button ota-button">OTA</button>
            <div id="settingsDropdown" class="dropdown">
                <button onclick="location.href='/setting_bluetooth_jam'" class="dropdown-button hidden">Bluetooth Jam</button>
                <button onclick="location.href='/setting_drone_jam'" class="dropdown-button hidden">Drone Jam</button>
                <button onclick="location.href='/setting_separate_together'" class="dropdown-button hidden">Отдельно или Вместе</button>
                <button onclick="location.href='/setting_misc_jam'" class="dropdown-button hidden">Misc Jam</button>
                <button onclick="location.href='/wifi_settings'" class="dropdown-button hidden">WiFi настройки</button>
            </div>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_ota = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
            transition: background-color 0.5s;
            opacity: 0;
            animation: fadeIn 1s forwards;
        }

        @keyframes fadeIn {
            from {
                opacity: 0;
            }
            to {
                opacity: 1;
            }
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 400px;
            position: relative;
            transform: translateY(20px);
            animation: slideIn 0.5s forwards;
        }

        @keyframes slideIn {
            from {
                transform: translateY(20px);
                opacity: 0;
            }
            to {
                transform: translateY(0);
                opacity: 1;
            }
        }

        h2 {
            margin-bottom: 20px;
        }

        .file-upload {
            position: relative;
            margin-top: 10px;
        }

        .file-upload input[type="file"] {
            display: none;
        }

        .file-upload label {
            display: inline-block;
            background-color: #5900ff;
            color: white;
            padding: 10px 20px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
        }

        .file-upload label:hover {
            background-color: #4201bc;
            transform: translateY(-4px) scale(1.05);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button {
            background-color: #2ae168;
            border: none;
            color: white;
            padding: 10px 20px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin-top: 20px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
        }

        .button:hover {
            background-color: #218838;
            transform: translateY(-4px) scale(1.05);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(2px);
        }

        .hint {
            margin-top: 10px;
            font-size: 14px;
            color: #cccccc;
        }

        .warning {
            margin-top: 15px;
            font-size: 14px;
            color: #ffcc00;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Firmware Update</h2>
        <form enctype='multipart/form-data' action='/update' method='POST'>
            <div class="file-upload">
                <label for="file-upload">Выберите файл</label>
                <input type='file' id="file-upload" name='update' accept=".bin" required>
            </div>
            <button class="button" type="submit">Загрузить</button>
            <div class="hint">Пожалуйста, выберите файл .bin для обновления.</div>
            <div class="warning">⚠️ Не выбирайте загрузчика или файлы раздела!</div>
        </form>
    </div>
</body>
</html>
)rawliteral";

const char* html_upload_progress = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        #progress {
            width: 100%;
            background-color: #ddd;
            border-radius: 5px;
            overflow: hidden;
        }

        #progress-bar {
            width: 0;
            height: 30px;
            background-color: #5900ff;
            text-align: center;
            color: white;
            transition: width 0.2s;
        }

        #status {
            margin-top: 10px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Загрузка прошивки...</h2>
        <div id="progress">
            <div id="progress-bar">0%</div>
        </div>
        <div id="status"></div>
    </div>
    <script>
        function updateProgress(percent) {
            const progressBar = document.getElementById("progress-bar");
            progressBar.style.width = percent + '%';
            progressBar.innerHTML = percent + '%';
        }
    </script>
</body>
</html>
)rawliteral";

const char* html_pls_reboot = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #5900ff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #5900ff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Пожалуйста, перезагрузитесь</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '#';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_misc_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #5900ff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #5900ff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Заглушение выбранных каналов</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '#';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_bluetooth_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #5900ff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #5900ff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Bluetooth Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '#';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_drone_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #5900ff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #5900ff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Drone Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '#';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_wifi_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #5900ff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #5900ff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">WiFi Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '#';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_ble_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #5900ff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #5900ff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">BLE Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '#';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_zigbee_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #5900ff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #5900ff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Zigbee Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '#';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_bluetooth_setings = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #4201bc; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Выберите jamming тип:</h1>
        </div>

        <div class="buttons">
            <button class="button" onclick="location.href='/bluetooth_method_0'">Brute Force по списку (21)</button>
            <button class="button" onclick="location.href='/bluetooth_method_1'">Рандомные значения (0-79)</button>
            <button class="button" onclick="location.href='/bluetooth_method_2'">Brute Force по значениям (0-79)</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_drone_setings = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #4201bc; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Выберите jamming тип:</h1>
        </div>

        <div class="buttons">
            <button class="button" onclick="location.href='/drone_method_0'">Рандомные значения (0-125)</button>
            <button class="button" onclick="location.href='/drone_method_1'">Brute Force по значениям (0-125)</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_misc_setings = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #4201bc; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Выберите jamming тип:</h1>
        </div>
        <div class="buttons">
            <button class="button" onclick="location.href='/misc_method_0'">Переключение канала (Fast Mode; используется в JAM Bluetooth)</button>
            <button class="button" onclick="location.href='/misc_method_1'">Отправка пакета (slow mode; используется в WiFi Jam)</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_separate_or_together = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #4201bc; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Выберите Jamming тип:</h1>
        </div>
        <div class="buttons">
            <button class="button" onclick="location.href='/separate_or_together_method_0'">Модули на разных каналах</button>
            <button class="button" onclick="location.href='/separate_or_together_method_1'">Модули на том же канале</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_wifi_select = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #4201bc; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Выберите Jamming тип:</h1>
        </div>

        <div class="buttons">
            <button class="button" onclick="location.href='/wifi_jam'">Jam все каналы</button>
            <button class="button" onclick="location.href='/wifi_channel'">Выберите канал для Jam</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_wifi_channel = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .input {
            background-color: #333333;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-size: 16px;
            width: 100%;
            margin-bottom: 15px;
            text-align: center;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
        }

        .input:focus {
            outline: none;
            background-color: #444444;
            box-shadow: 0 0 8px rgba(0, 123, 255, 0.5);
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px);
        }

        .button:focus {
            outline: none;
        }
    </style>
    <script>
        function validateAndRedirect() {
            const channelValue = parseInt(document.getElementById('channelInput').value);

            if (isNaN(channelValue) || channelValue < 0 || channelValue > 12) {
                alert('Channel must be a number between 0 and 12.');
                return;
            }
            location.href = `/wifi_selected_jam?channel=${channelValue}`;
        }
    </script>
</head>
<body>
    <div class="container">
        <h1>Jam Channel:</h1>
        <input id="channelInput" class="input" type="number" placeholder="Channel (0-12)" max="12" min="0" />
        <button class="button" onclick="validateAndRedirect()">Подтвердить</button>
    </div>
</body>
</html>
)rawliteral";

const char* html_wifi_settings = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
            opacity: 0;
            animation: fadeIn 1s forwards;
        }

        @keyframes fadeIn {
            from { opacity: 0; }
            to { opacity: 1; }
        }

        .container {
            display: flex;
            flex-direction: column;
            align-items: center;
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
            transform: translateY(20px);
            animation: slideIn 0.5s forwards;
        }

        @keyframes slideIn {
            from {
                transform: translateY(20px);
                opacity: 0;
            }
            to {
                transform: translateY(0);
                opacity: 1;
            }
        }

        .input {
            background-color: #333333;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-size: 16px;
            width: 100%;
            box-sizing: border-box;
            margin: 0 auto 15px;
            text-align: center;
            transition: background-color 0.3s, transform 0.2s;
        }

        .input:focus {
            outline: none;
            background-color: #444444;
            box-shadow: 0 0 8px rgba(0, 123, 255, 0.5);
        }

        label {
            display: block;
            margin-bottom: 8px;
            font-size: 14px;
            color: #aaaaaa;
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: calc(100% - 20px);
            box-sizing: border-box;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
            margin: 5px auto;
        }

        .button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px);
        }

        .button.reset {
            background-color: #dc3545;
        }

        .button.reset:hover {
            background-color: #c82333;
        }

        .warning {
            margin-top: 15px;
            font-size: 14px;
            color: #ffcc00;
            text-align: center;
            padding: 10px;
            border-radius: 5px;
            background-color: rgba(255, 204, 0, 0.1);
        }

        .notification {
            position: fixed;
            top: -100px;
            left: 50%;
            transform: translateX(-50%);
            padding: 15px 25px;
            border-radius: 0 0 8px 8px;
            color: white;
            font-weight: bold;
            z-index: 1000;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.2);
            transition: top 0.5s ease-out;
            width: 80%;
            max-width: 400px;
            text-align: center;
            opacity: 0;
            animation: notificationFadeIn 0.3s forwards;
        }

        @keyframes notificationFadeIn {
            from { opacity: 0; }
            to { opacity: 1; }
        }

        .success {
            background: linear-gradient(135deg, #2ae168, #218838);
        }

        .error {
            background: linear-gradient(135deg, #dc3545, #c82333);
        }
    </style>
</head>
<body>
    <div id="notification" class="notification" style="display: none;"></div>

    <div class="container">
        <h1>WiFi настройки</h1>
        <form id="wifiForm">
            <input type="text" id="ssid" name="ssid" placeholder="Введите SSID" class="input">
            <input type="password" id="password" name="password" placeholder="Введите пароль" class="input">
            <button type="button" onclick="validateAndSave()" class="button">Сохранить настройки</button>
            <button type="button" onclick="confirmReset()" class="button reset">Сброс к "по умолчанию"</button>
        </form>
    </div>

    <script>
        function showNotification(message, isSuccess) {
            const notification = document.getElementById("notification");
            notification.textContent = message;
            notification.className = isSuccess ? "notification success" : "notification error";
            notification.style.display = "block";

            setTimeout(() => {
                notification.style.top = "20px";
            }, 10);

            setTimeout(() => {
                notification.style.top = "-100px";
                setTimeout(() => {
                    notification.style.display = "none";
                }, 500);
            }, 3000);
        }

        function validateAndSave() {
            const ssid = document.getElementById("ssid").value;
            const password = document.getElementById("password").value;
            
            if (ssid.length === 0 && password.length === 0) {
                showNotification("SSID должен содержать не менее 1 символа, а пароль - не менее 8 символов", false);
                return;
            }

            if (ssid.length === 0) {
                showNotification("SSID должен содержать не менее 1 символа", false);
                return;
            }

            if (password.length === 0) {
                showNotification("Пароль должен содержать не менее 8 символов", false);
                return;
            }

            if (password.length < 8) {
                showNotification("Пароль должен содержать не менее 8 символов", false);
                return;
            }

            const formData = new FormData();
            formData.append("ssid", ssid);
            formData.append("password", password);

            showNotification("Сохранение настроек...", true);

            fetch("/save_wifi_settings", {
                method: "POST",
                body: formData
            })
            .then(response => {
                if (response.ok) {
                    showNotification("Настройки успешно сохранены! Перезагрузка...", true);
                    setTimeout(() => {
                        window.location.reload();
                    }, 2000);
                } else {
                    showNotification("Ошибка сохрарения настроек", false);
                }
            })
            .catch(error => {
                console.error("Error:", error);
                showNotification("Connection error", false);
            });
        }

        function confirmReset() {
            if (confirm("Вы уверены, что хотите вернуться к настройкам по умолчанию?")) {
                showNotification("Сброс к настройкам по умолчанию...", true);
                setTimeout(() => {
                    location.href = "/reset_wifi_settings";
                }, 1000);
            }
        }
        
        document.addEventListener('keypress', function(e) {
            if (e.key === 'Enter') {
                validateAndSave();
            }
        });
    </script>
</body>
</html>
)rawliteral";

const char* html_misc_jammer = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            display: flex;
            flex-direction: column;
            align-items: center;
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .input {
            background-color: #333333;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-size: 16px;
            width: 100%;
            margin-bottom: 15px;
            text-align: center;
            transition: background-color 0.3s, transform 0.2s;
        }

        .input:focus {
            outline: none;
            background-color: #444444;
            box-shadow: 0 0 8px rgba(0, 123, 255, 0.5);
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #5900ff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #4201bc;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px);
        }

        .button:focus {
            outline: none;
        }
    </style>
    <script>
        function validateAndRedirect() {
            const startValue = parseInt(document.getElementById('startInput').value);
            const stopValue = parseInt(document.getElementById('stopInput').value);

            if (isNaN(startValue) || startValue < 0 || startValue > 125) {
                alert('Начальное значение должно быть числом от 0 до 125.');
                return;
            }
            if (isNaN(stopValue) || stopValue < 0 || stopValue > 125) {
                alert('Значение остановки должно быть числом от 0 до 125.');
                return;
            }
            if (stopValue < startValue) {
                alert('Значение остановки не должно быть меньше начального значения.');
                return;
            }
            location.href = `/misc_jam?start=${startValue}&stop=${stopValue}`;
        }
    </script>
</head>
<body>
    <div class="container">
        <h1>Установите значения Запуска/Остановки:</h1>
        <input id="startInput" class="input" type="number" placeholder="Start (0-125)" max="125" min="0" />
        <input id="stopInput" class="input" type="number" placeholder="Stop (0-125)" max="125" min="0" />
        <button class="button" onclick="validateAndRedirect()">Jam</button>
    </div>
</body>
</html>
)rawliteral";
