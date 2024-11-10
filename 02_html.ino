// HTML-Inhalt für die Startseite auf Deutsch
const char index_de_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
    <title>ESP Driftblitz</title>
    <link rel="stylesheet" href="styles.css">
    <script src="scripts_de.js" defer></script>
</head>
<body>
    <div class="container">
        <h2>ESP Driftblitz</h2>

        <h3>Distanz Einstellung (cm):</h3>
        <div class="distanz-einstellung">
            <input type="number" id="distanz-input" placeholder="Gib den Distanzwert ein">
            <button onclick="sendDistanzValue()">Setze Distanz</button>
        </div>

                <h3>Monitor:</h3> 
        <div class="monitor-box">
            <p id="monitor-output"></p>
        </div>


        <h3>System Infos:</h3>     

        <div class="system-info">
            <div class="info-row">
                <span class="info-label">Sensor Status:</span>
                <span class="info-value" id="sensor-status">-</span>
            </div>

            <div class="info-row">
                <span class="info-label">CPU Load Core:</span>
                <span class="info-value" id="cpu-core">-</span>
            </div>
            <div class="info-row">
                <span class="info-label">CPU Temperatur:</span>
                <span class="info-value" id="cpu-temp">-</span>
            </div>
            <div class="info-row">
                <span class="info-label">Freier RAM:</span>
                <span class="info-value" id="ram">-</span>
            </div>
        </div>

        <h3>Pin Einstellungen:</h3>
        <div class="pin-einstellungen">
            <div class="input-row">
                <label for="led-pin">LED Pin:</label>
                <input type="number" id="led-pin" placeholder="LED Pin-Nummer">
            </div>
            <div class="input-row">
                <label for="scl-pin">SCL Pin:</label>
                <input type="number" id="scl-pin" placeholder="SCL Pin-Nummer">
            </div>
            <div class="input-row">
                <label for="sda-pin">SDA Pin:</label>
                <input type="number" id="sda-pin" placeholder="SDA Pin-Nummer">
            </div>
            <button onclick="sendPinSettings()">Pins setzen</button>
        </div>


        <h3>Pin Einstellungen:</h3>
        <div class="pin-einstellungen">
            <div class="input-row">
                <label for="led-pin">LED Pin:</label>
                <input type="number" id="led-pin" placeholder="LED Pin-Nummer">
            </div>
            <div class="input-row">
                <label for="scl-pin">SCL Pin:</label>
                <input type="number" id="scl-pin" placeholder="SCL Pin-Nummer">
            </div>
            <div class="input-row">
                <label for="sda-pin">SDA Pin:</label>
                <input type="number" id="sda-pin" placeholder="SDA Pin-Nummer">
            </div>
            <button onclick="sendPinSettings()">Pins setzen</button>
        </div>



        <h3>WiFi Einstellungen:</h3>
        <div class="wifi-einstellungen">
            <div class="input-row">
                <label for="wifi-ssid">SSID:</label>
                <input type="text" id="wifi-ssid" placeholder="Gib den SSID ein">
            </div>
            <div class="input-row">
                <label for="wifi-password">Passwort:</label>
                <input type="text" id="wifi-password" placeholder="Gib das Passwort ein">
            </div>
            <button onclick="sendWifiSettings()">WiFi Einstellungen setzen</button>
        </div>




        <h3>Firmware Update:</h3>
        <!-- Firmware Upload Form -->
        <form id="uploadForm" action="/upload" method="post" enctype="multipart/form-data">
            <div class="upload-container">
                <input type="file" id="fileInput" name="firmware">
                <input type="submit" value="Hochladen">
            </div>
        </form>
        
        <!-- Abschlussbereich -->        
        <div class="footer-content">
            <p>Driftblitz © 2024</p>
            <p>Board: ESP32</p>
            <p>powered by DCB</p>
        </div>

        <button id="toggleButton" class="toggle-button" onclick="toggleNightMode()">
            <div class="icon" id="icon"></div>
        </button>
    </div>

    <!-- Toast-Benachrichtigung -->
    <div id="toast" class="toast">Aktion erfolgreich</div>
</body>
</html>
)rawliteral";

// HTML-Inhalt für die Startseite auf Englisch
const char index_en_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
    <title>ESP Driftblitz</title>
    <link rel="stylesheet" href="styles.css">
    <script src="scripts_en.js" defer></script>
</head>
<body>
    <div class="container">
        <h2>ESP Driftblitz</h2>

        <h3>Distance Setting (cm):</h3>
        <div class="distanz-einstellung">
            <input type="number" id="distanz-input" placeholder="Enter distance value">
            <button onclick="sendDistanzValue()">Set Distance</button>
        </div>


        <h3>Monitor:</h3> 
        <div class="monitor-box">
            <p id="monitor-output"></p>
        </div>


       <h3>System Info:</h3>     

        <div class="system-info">
            <div class="info-row">
                <span class="info-label">Sensor Status:</span>
                <span class="info-value" id="sensor-status">-</span>
            </div>

            <div class="info-row">
                <span class="info-label">CPU Load Core:</span>
                <span class="info-value" id="cpu-core">-</span>
            </div>
            <div class="info-row">
                <span class="info-label">CPU Temperature:</span>
                <span class="info-value" id="cpu-temp">-</span>
            </div>
            <div class="info-row">
                <span class="info-label">Free RAM:</span>
                <span class="info-value" id="ram">-</span>
            </div>
        </div>


        <h3>Pin Settings:</h3>
        <div class="pin-einstellungen">
            <div class="input-row">
                <label for="led-pin">LED Pin:</label>
                <input type="number" id="led-pin" placeholder="LED Pin Number">
            </div>
            <div class="input-row">
                <label for="scl-pin">SCL Pin:</label>
                <input type="number" id="scl-pin" placeholder="SCL Pin Number">
            </div>
            <div class="input-row">
                <label for="sda-pin">SDA Pin:</label>
                <input type="number" id="sda-pin" placeholder="SDA Pin Number">
            </div>
            <button onclick="sendPinSettings()">Set Pins</button>
        </div>

        <h3>WiFi Settings:</h3>
        <div class="wifi-einstellungen">
            <div class="input-row">
                <label for="wifi-ssid">SSID:</label>
                <input type="text" id="wifi-ssid" placeholder="Enter SSID">
            </div>
            <div class="input-row">
                <label for="wifi-password">Password:</label>
                <input type="text" id="wifi-password" placeholder="Enter Password">
            </div>
            <button onclick="sendWifiSettings()">Set WiFi Settings</button>
        </div>




        <h3>Firmware Update:</h3>
        <!-- Firmware Upload Form -->
        <form id="uploadForm" action="/upload" method="post" enctype="multipart/form-data">
            <div class="upload-container">
                <input type="file" id="fileInput" name="firmware">
                <input type="submit" value="Upload">
            </div>
        </form>
        
        <!-- Footer Section -->
        <div class="footer-content">
            <p>Driftblitz © 2024</p>
            <p>Board: ESP32</p>
            <p>powered by DCB</p>
        </div>

        <button id="toggleButton" class="toggle-button" onclick="toggleNightMode()">
            <div class="icon" id="icon"></div>
        </button>
    </div>

    <!-- Toast Notification -->
    <div id="toast" class="toast">Action successful</div>
</body>
</html>
)rawliteral";

// CSS-Inhalt bleibt unverändert
const char styles_css[] PROGMEM = R"rawliteral(
:root {
    --bg-color: #f4f4f4;
    --text-color: #333;
    --container-bg-color: white;
    --container-shadow: rgba(0, 0, 0, 0.1);
    --container-border-color: #ccc;
    --button-ring-color: #333;
    --button-bg-color: var(--text-color);
    --footer-bg-color: #f0f0f0;

    --info-bg-color: #fafafa;
    --info-text-color: #555;
    --info-value-color: #333;

    --input-bg-color: white;
    --input-text-color: #333;
    --button-text-color: #333;

    --toast-bg-color: #333;
    --toast-text-color: #fff;
}

body.night-mode {
    --bg-color: #333;
    --text-color: #fff;
    --container-bg-color: #444;
    --container-shadow: rgba(0, 0, 0, 0.5);
    --container-border-color: #444;
    --button-ring-color: #fff;
    --button-bg-color: #666;
    --footer-bg-color: #4a4a4a;

    --info-bg-color: #4a4a4a;
    --info-text-color: #bbb;
    --info-value-color: #fff;

    --input-bg-color: #555;
    --input-text-color: #fff;
    --button-text-color: #fff;

    --toast-bg-color: #fff;
    --toast-text-color: #000;
}

body {
    font-family: Arial, sans-serif;
    margin: 0;
    padding: 0;
    background-color: var(--bg-color);
    color: var(--text-color);
    height: auto;
    display: flex;
    justify-content: center;
    align-items: flex-start;
    margin-bottom: 20px;
    overflow: auto;
}

.container {
    background-color: var(--container-bg-color);
    border-radius: 10px;
    padding: 20px;
    border: 2px solid var(--container-border-color);
    box-shadow: 0 4px 10px var(--container-shadow);
    position: relative;
    width: 90%;
    max-width: 450px;
    box-sizing: border-box;
    margin-top: 20px;
    min-height: 90vh;
}

.container h2, .container h3 {
    text-align: center;
    font-size: 24px;
}

button.toggle-button {
    width: 50px;
    height: 50px;
    border-radius: 50%;
    border: 2px solid var(--button-ring-color);
    background-color: var(--button-bg-color);
    color: var(--bg-color);
    position: absolute;
    top: 20px;
    right: 20px;
    cursor: pointer;
    z-index: 10;
    display: flex;
    justify-content: center;
    align-items: center;
}

button.toggle-button .icon {
    width: 24px;
    height: 24px;
    background-image: url("data:image/svg+xml;charset=UTF-8,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='%23ffffff'><path d='M12 1a9 9 0 0 0 0 18 9 9 0 0 0 0-18zm0 16a7 7 0 1 1 0-14 7 7 0 0 1 0 14z'/></svg>");
    background-repeat: no-repeat;
    background-position: center;
}

body.night-mode button.toggle-button .icon {
    background-image: url("data:image/svg+xml;charset=UTF-8,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24' fill='%23ffffff'><path d='M12 1a9 9 0 0 0 0 18 9 9 0 0 0 0-18zm0 16a7 7 0 1 1 0-14 7 7 0 0 1 0 14z'/></svg>");
}

.monitor-box {
    background-color: var(--footer-bg-color); 
    border: 2px solid var(--container-border-color);
    padding: 10px;
    height: 155px;
    overflow-y: auto;
    margin-top: 10px;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    font-family: monospace;
    font-size: 14px;
    text-align: left;
}

.footer-content {
    text-align: center;
    padding: 10px;
    background-color: var(--footer-bg-color); 
    font-size: 14px;
    margin-top: 20px;
    border-radius: 5px;
    box-shadow: 0 -2px 10px rgba(0, 0, 0, 0.1);
}

.upload-container {
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.upload-container input[type="file"] {
    flex-grow: 1;
    margin-right: 5px;
    max-width: 65%;
}

.upload-container input[type="submit"] {
    flex-shrink: 0;
    background-color: var(--footer-bg-color);
    color: var(--button-text-color);
    border: 2px solid var(--container-border-color);
    padding: 8px 10px;
    border-radius: 5px;
    cursor: pointer;
}

@media (max-width: 768px) {
    .container {
        padding: 8px;
        margin-top: 20px;
        width: 95%;
    }

    button.toggle-button {
        width: 40px;
        height: 40px;
        top: 10px;
        right: 10px;
    }

    button.toggle-button .icon {
        width: 20px;
        height: 20px;
    }

    .upload-container input[type="file"] {
        max-width: 65%;
    }

    .upload-container input[type="submit"] {
        padding: 6px 8px;
        font-size: 14px;
    }
}

.system-info {
    display: flex;
    flex-direction: column;
    gap: 8px;
    margin-top: 10px;
}

.info-row {
    display: flex;
    justify-content: space-between;
    padding: 8px 12px;
    border-radius: 5px;
    background-color: var(--info-bg-color);
    box-shadow: 0 1px 2px rgba(0, 0, 0, 0.05);
}

.info-label {
    font-weight: normal;
    color: var(--info-text-color);
}

.info-value {
    color: var(--info-value-color);
}

.distanz-einstellung, .pin-einstellungen, .wifi-einstellungen {
    margin-top: 10px;
}

.distanz-einstellung input[type="number"],
.pin-einstellungen input[type="number"],
.wifi-einstellungen input[type="text"] {
    flex-grow: 1;
    margin-right: 5px;
    padding: 8px;
    border: 2px solid var(--container-border-color);
    border-radius: 5px;
    background-color: var(--input-bg-color);
    color: var(--input-text-color);
}

.distanz-einstellung input[type="number"]::placeholder,
.pin-einstellungen input[type="number"]::placeholder,
.wifi-einstellungen input[type="text"]::placeholder {
    color: var(--input-text-color);
    opacity: 0.7;
}

.distanz-einstellung button,
.pin-einstellungen button,
.wifi-einstellungen button {
    flex-shrink: 0;
    padding: 8px 12px;
    background-color: var(--footer-bg-color);
    color: var(--button-text-color);
    border: 2px solid var(--container-border-color);
    border-radius: 5px;
    cursor: pointer;
}

.input-row {
    display: flex;
    align-items: center;
    margin-bottom: 5px;
}

.input-row label {
    flex-basis: 40%;
}

.input-row input {
    flex-basis: 60%;
}

#cpu-core, #cpu-temp, #ram, #sensor-status, #wifi-ssid, #wifi-password {
    color: inherit;
}

/* Toast Notification */
.toast {
    visibility: hidden;
    min-width: 200px;
    background-color: var(--toast-bg-color);
    color: var(--toast-text-color);
    text-align: center;
    border-radius: 4px;
    padding: 12px;
    position: fixed;
    z-index: 1;
    left: 50%;
    top: 20px;
    transform: translateX(-50%);
    font-size: 17px;
}

.toast.show {
    visibility: visible;
    -webkit-animation: fadein 0.5s, fadeout 0.5s 2.5s;
    animation: fadein 0.5s, fadeout 0.5s 2.5s;
}

@-webkit-keyframes fadein {
    from {top: 0; opacity: 0;}
    to {top: 20px; opacity: 1;}
}

@keyframes fadein {
    from {top: 0; opacity: 0;}
    to {top: 20px; opacity: 1;}
}

@-webkit-keyframes fadeout {
    from {top: 20px; opacity: 1;}
    to {top: 0; opacity: 0;}
}

@keyframes fadeout {
    from {top: 20px; opacity: 1;}
    to {top: 0; opacity: 0;}
}
)rawliteral";

// JavaScript-Inhalt für Deutsch
const char scripts_de_js[] PROGMEM = R"rawliteral(
var socket = null;
var reconnectInterval;
var lastSentProgress = 0;
var isConnected = false;
var isDisplayed = false;
var lastMessageTime = Date.now();  // Zeitstempel der letzten empfangenen Nachricht

// Konstante für die maximale Anzahl an Nachrichten
const MAX_MESSAGES = 100;

function connectWebSocket() {
    console.log("connectWebSocket aufgerufen, socket:", socket);

    if (socket) {
        if (socket.readyState === WebSocket.OPEN) {
            console.log("WebSocket-Verbindung besteht bereits.");
            return;
        } else {
            console.log("Schließe bestehende WebSocket-Verbindung.");
            socket.close();
        }
    }

    console.log("Erstelle neue WebSocket-Verbindung");
    socket = new WebSocket(`ws://${window.location.hostname}/ws`);

    socket.onopen = function(event) {
        console.log("WebSocket onopen ausgelöst");

        lastMessageTime = Date.now();

        if (!isDisplayed) {
            var monitorOutput = document.getElementById('monitor-output');
            var currentTime = new Date().toLocaleTimeString();
            monitorOutput.innerHTML += `${currentTime} -> WebSocket verbunden<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
            isDisplayed = true;
        }

        isConnected = true;

        clearInterval(reconnectInterval);
    };

    // In der WebSocket onmessage Funktion:
    socket.onmessage = function(event) {
        lastMessageTime = Date.now();

        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();

        try {
            var data = JSON.parse(event.data);

            // Update System Info
            if (data.cpuLoad !== undefined) {
                document.getElementById('cpu-core').innerText = data.cpuLoad.toFixed(2) + "%";
            }
            if (data.cpuTemp !== undefined) {
                document.getElementById('cpu-temp').innerText = data.cpuTemp.toFixed(2) + " °C";
            }
            if (data.freeRAM !== undefined && data.ramFreePercent !== undefined) {
                document.getElementById('ram').innerText = `${data.freeRAM} kB (${data.ramFreePercent.toFixed(2)}% frei)`;
            }
            if (data.sensorStatus !== undefined) {
                document.getElementById('sensor-status').innerText = data.sensorStatus;
            }
            if (data.distance !== undefined) {
                var distanceInCm = data.distance / 10;  // Convert mm to cm
                monitorOutput.innerHTML += `${currentTime} -> Distanz: ${distanceInCm.toFixed(1)} cm<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
            }
            if (data.message === "LED AN") {
                monitorOutput.innerHTML += `${currentTime} -> LED AN<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
            }

            // Handle other types of messages
            if (data.type === 'currentDistanz') {
                document.getElementById('distanz-input').value = parseFloat(data.value).toFixed(2);
            } else if (data.type === 'distanzSet') {
                var formattedValue = parseFloat(data.value).toFixed(2);
                monitorOutput.innerHTML += `${currentTime} -> Distanz eingestellt auf: ${formattedValue} cm<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                showToast('Distanz erfolgreich gespeichert');
            } else if (data.type === 'currentPins') {
                document.getElementById('led-pin').value = data.ledPin;
                document.getElementById('scl-pin').value = data.sclPin;
                document.getElementById('sda-pin').value = data.sdaPin;
            } else if (data.type === 'pinsSet') {
                monitorOutput.innerHTML += `${currentTime} -> Pins erfolgreich gespeichert<br>Neustart, bitte einen Moment warten<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                showToast('Pins erfolgreich gespeichert');

                // **Zeige Neustart-Toast in roter Farbe mit benutzerdefinierter Nachricht**
                setTimeout(function() {
                    showToast('Neustart', 'red');
                }, 1000);
            } else if (data.type === 'rebooting') {
                // **Ausgabe im Monitor mit benutzerdefinierter Nachricht**
                var rebootMessage = data.message || 'Neustart';
                monitorOutput.innerHTML += `${currentTime} -> ${rebootMessage}<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                // **Zeige Neustart-Toast in roter Farbe mit benutzerdefinierter Nachricht**
                showToast(rebootMessage, 'red');
            }
            else if (data.type === 'currentWifi') {
                // Aktualisiere die WiFi-Eingabefelder mit den aktuellen Werten
                document.getElementById('wifi-ssid').value = data.ssid;
                document.getElementById('wifi-password').value = data.password;
            }
            else if (data.type === 'wifiSet') {
                if (data.status === "success") {
                    monitorOutput.innerHTML += `${currentTime} -> WiFi Einstellungen erfolgreich gespeichert<br>`;
                    limitMonitorMessages();
                    document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                    showToast('WiFi Einstellungen erfolgreich gespeichert');

                    // **Zeige Neustart-Toast in roter Farbe mit benutzerdefinierter Nachricht**
                    setTimeout(function() {
                        showToast('Neustart zur Anwendung der neuen WiFi-Einstellungen', 'red');
                    }, 1000);
                } else if (data.status === "error") {
                    monitorOutput.innerHTML += `${currentTime} -> ${data.message}<br>`;
                    limitMonitorMessages();
                    document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                    showToast(data.message, 'red');
                }
            }
        } catch (e) {
            monitorOutput.innerHTML += `${currentTime} -> ${event.data}<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
        }
    };


    socket.onclose = function(event) {
        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();

        if (isConnected) {
            monitorOutput.innerHTML += `${currentTime} -> Verbindung geschlossen<br>`;
            monitorOutput.innerHTML += `${currentTime} -> Versuche, die Verbindung wiederherzustellen...<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
        }

        isConnected = false;
        isDisplayed = false;
        console.log("WebSocket Verbindung geschlossen, Flags zurückgesetzt.");

        socket = null;

        // Sofortigen Verbindungsversuch starten
        reconnectInterval = setTimeout(connectWebSocket, 1000);
    };

    socket.onerror = function(error) {
        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();

        if (isConnected) {
            monitorOutput.innerHTML += `${currentTime} -> Fehler bei der WebSocket-Verbindung<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
        }

        isConnected = false;
        isDisplayed = false;
        console.log("WebSocket Fehler, Flags zurückgesetzt.");

        socket = null;

        // Sofortigen Verbindungsversuch starten
        reconnectInterval = setTimeout(connectWebSocket, 1000);
    };
}

// Funktion zur Begrenzung der Nachrichten im Monitor auf MAX_MESSAGES
function limitMonitorMessages() {
    var monitorOutput = document.getElementById('monitor-output');
    var messages = monitorOutput.innerHTML.split('<br>');
    
    // Entferne leere Elemente, die durch das letzte <br> entstehen können
    messages = messages.filter(message => message.trim() !== '');
    
    if (messages.length > MAX_MESSAGES) {
        // Behalte nur die letzten MAX_MESSAGES Nachrichten
        var trimmedMessages = messages.slice(-MAX_MESSAGES);
        monitorOutput.innerHTML = trimmedMessages.join('<br>') + '<br>';
    }
}

document.getElementById('uploadForm').onsubmit = function(event) {
    event.preventDefault(); 

    var formData = new FormData(document.getElementById('uploadForm'));
    var xhr = new XMLHttpRequest();
    
    xhr.open('POST', '/upload', true);

    xhr.upload.onprogress = function(e) {
        if (e.lengthComputable) {
            var percentComplete = (e.loaded / e.total) * 100;
            var roundedProgress = Math.round(percentComplete);

            if (roundedProgress - lastSentProgress >= 10 || roundedProgress === 100) {
                var monitorOutput = document.getElementById('monitor-output');
                var currentTime = new Date().toLocaleTimeString();
                monitorOutput.innerHTML += `${currentTime} -> Fortschritt: ${roundedProgress}%<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
                lastSentProgress = roundedProgress;
            }
        }
    };

    xhr.onload = function() {
        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();
        if (xhr.status == 200) {
            monitorOutput.innerHTML += `${currentTime} -> Update abgeschlossen.<br>`;
        } else {
            monitorOutput.innerHTML += `${currentTime} -> Update fehlgeschlagen.<br>`;
        }
        limitMonitorMessages();
        document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
    };

    xhr.send(formData);
};

function sendDistanzValue() {
    var distanzValue = document.getElementById('distanz-input').value;
    if (socket && socket.readyState === WebSocket.OPEN) {
        socket.send(JSON.stringify({type: 'setDistanz', value: distanzValue}));
    } else {
        alert('WebSocket ist nicht verbunden.');
    }
}

function sendPinSettings() {
    var ledPin = document.getElementById('led-pin').value;
    var sclPin = document.getElementById('scl-pin').value;
    var sdaPin = document.getElementById('sda-pin').value;
    if (socket && socket.readyState === WebSocket.OPEN) {
        socket.send(JSON.stringify({
            type: 'setPins',
            ledPin: parseInt(ledPin),
            sclPin: parseInt(sclPin),
            sdaPin: parseInt(sdaPin)
        }));
    } else {
        alert('WebSocket ist nicht verbunden.');
    }
}

function sendWifiSettings() {
    var ssidValue = document.getElementById('wifi-ssid').value;
    var passwordValue = document.getElementById('wifi-password').value;

    // Passwortvalidierung: mindestens 8 Zeichen
    if (passwordValue.length < 8) {
        showToast('Passwort muss mindestens 8 Zeichen lang sein.', 'red');
        return;
    }

    if (socket && socket.readyState === WebSocket.OPEN) {
        socket.send(JSON.stringify({
            type: 'setWifi',
            ssid: ssidValue,
            password: passwordValue
        }));
    } else {
        alert('WebSocket ist nicht verbunden.');
    }
}

function showToast(message, color) {
    var toast = document.getElementById('toast');
    toast.innerText = message;
    if (color) {
        toast.style.backgroundColor = color;
    } else {
        toast.style.backgroundColor = '';  // Standardfarbe
    }
    toast.className = 'toast show';
    setTimeout(function() {
        toast.className = toast.className.replace('show', '');
        toast.style.backgroundColor = '';  // Zurücksetzen
    }, 3000);
}

function toggleNightMode() {
    document.body.classList.toggle('night-mode');
    var isNightMode = document.body.classList.contains('night-mode');
    document.cookie = "nightMode=" + (isNightMode ? "1" : "0") + ";path=/;max-age=31536000";
}

(function() {
    var nightModeCookie = document.cookie.split('; ').find(row => row.startsWith('nightMode'));
    if (nightModeCookie) {
        var isNightMode = nightModeCookie.split('=')[1] === "1";
        if (isNightMode) {
            document.body.classList.add('night-mode');
        }
    }
})();

// Heartbeat-Mechanismus
setInterval(function() {
    var currentTime = Date.now();
    if (currentTime - lastMessageTime > 5000) { // Wenn seit 5 Sekunden keine Nachricht empfangen wurde
        console.log("Keine Nachrichten in den letzten 5 Sekunden empfangen. Versuche, die Verbindung wiederherzustellen.");
        if (socket) {
            socket.close();
        }
        connectWebSocket();
    }
}, 5000);

window.onload = function() {
    setTimeout(connectWebSocket, 1000);
};
)rawliteral";

// JavaScript-Inhalt für Englisch
const char scripts_en_js[] PROGMEM = R"rawliteral(
var socket = null;
var reconnectInterval;
var lastSentProgress = 0;
var isConnected = false;
var isDisplayed = false;
var lastMessageTime = Date.now();  // Timestamp of the last received message

// Constant for the maximum number of messages
const MAX_MESSAGES = 100;

function connectWebSocket() {
    console.log("connectWebSocket called, socket:", socket);

    if (socket) {
        if (socket.readyState === WebSocket.OPEN) {
            console.log("WebSocket connection already exists.");
            return;
        } else {
            console.log("Closing existing WebSocket connection.");
            socket.close();
        }
    }

    console.log("Creating new WebSocket connection");
    socket = new WebSocket(`ws://${window.location.hostname}/ws`);

    socket.onopen = function(event) {
        console.log("WebSocket onopen triggered");

        lastMessageTime = Date.now();

        if (!isDisplayed) {
            var monitorOutput = document.getElementById('monitor-output');
            var currentTime = new Date().toLocaleTimeString();
            monitorOutput.innerHTML += `${currentTime} -> WebSocket connected<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
            isDisplayed = true;
        }

        isConnected = true;

        clearInterval(reconnectInterval);
    };

    // In the WebSocket onmessage function:
    socket.onmessage = function(event) {
        lastMessageTime = Date.now();

        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();

        try {
            var data = JSON.parse(event.data);

            // Update System Info
            if (data.cpuLoad !== undefined) {
                document.getElementById('cpu-core').innerText = data.cpuLoad.toFixed(2) + "%";
            }
            if (data.cpuTemp !== undefined) {
                document.getElementById('cpu-temp').innerText = data.cpuTemp.toFixed(2) + " °C";
            }
            if (data.freeRAM !== undefined && data.ramFreePercent !== undefined) {
                document.getElementById('ram').innerText = `${data.freeRAM} kB (${data.ramFreePercent.toFixed(2)}% free)`;
            }
            if (data.sensorStatus !== undefined) {
                document.getElementById('sensor-status').innerText = data.sensorStatus;
            }
            if (data.distance !== undefined) {
                var distanceInCm = data.distance / 10;  // Convert mm to cm
                monitorOutput.innerHTML += `${currentTime} -> Distance: ${distanceInCm.toFixed(1)} cm<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
            }
            if (data.message === "LED AN") {
                monitorOutput.innerHTML += `${currentTime} -> LED ON<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
            }

            // Handle other types of messages
            if (data.type === 'currentDistanz') {
                document.getElementById('distanz-input').value = parseFloat(data.value).toFixed(2);
            } else if (data.type === 'distanzSet') {
                var formattedValue = parseFloat(data.value).toFixed(2);
                monitorOutput.innerHTML += `${currentTime} -> Distance set to: ${formattedValue} cm<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                showToast('Distance successfully saved');
            } else if (data.type === 'currentPins') {
                document.getElementById('led-pin').value = data.ledPin;
                document.getElementById('scl-pin').value = data.sclPin;
                document.getElementById('sda-pin').value = data.sdaPin;
            } else if (data.type === 'pinsSet') {
                monitorOutput.innerHTML += `${currentTime} -> Pins successfully saved<br>Restarting, please wait a moment<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                showToast('Pins successfully saved');

                // **Show restart toast in red color with custom message**
                setTimeout(function() {
                    showToast('Restarting', 'red');
                }, 1000);
            } else if (data.type === 'rebooting') {
                // **Display in monitor with custom message**
                var rebootMessage = data.message || 'Restarting';
                monitorOutput.innerHTML += `${currentTime} -> ${rebootMessage}<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                // **Show restart toast in red color with custom message**
                showToast(rebootMessage, 'red');
            }
            else if (data.type === 'currentWifi') {
                // Update WiFi input fields with current values
                document.getElementById('wifi-ssid').value = data.ssid;
                document.getElementById('wifi-password').value = data.password;
            }
            else if (data.type === 'wifiSet') {
                if (data.status === "success") {
                    monitorOutput.innerHTML += `${currentTime} -> WiFi settings successfully saved<br>`;
                    limitMonitorMessages();
                    document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                    showToast('WiFi settings successfully saved');

                    // **Show restart toast in red color with custom message**
                    setTimeout(function() {
                        showToast('Restarting to apply new WiFi settings', 'red');
                    }, 1000);
                } else if (data.status === "error") {
                    monitorOutput.innerHTML += `${currentTime} -> ${data.message}<br>`;
                    limitMonitorMessages();
                    document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;

                    showToast(data.message, 'red');
                }
            }
        } catch (e) {
            monitorOutput.innerHTML += `${currentTime} -> ${event.data}<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
        }
    };


    socket.onclose = function(event) {
        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();

        if (isConnected) {
            monitorOutput.innerHTML += `${currentTime} -> Connection closed<br>`;
            monitorOutput.innerHTML += `${currentTime} -> Attempting to reconnect...<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
        }

        isConnected = false;
        isDisplayed = false;
        console.log("WebSocket connection closed, flags reset.");

        socket = null;

        // Start immediate reconnection attempt
        reconnectInterval = setTimeout(connectWebSocket, 1000);
    };

    socket.onerror = function(error) {
        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();

        if (isConnected) {
            monitorOutput.innerHTML += `${currentTime} -> WebSocket connection error<br>`;
            limitMonitorMessages();
            document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
        }

        isConnected = false;
        isDisplayed = false;
        console.log("WebSocket error, flags reset.");

        socket = null;

        // Start immediate reconnection attempt
        reconnectInterval = setTimeout(connectWebSocket, 1000);
    };
}

// Funktion zur Begrenzung der Nachrichten im Monitor auf MAX_MESSAGES
function limitMonitorMessages() {
    var monitorOutput = document.getElementById('monitor-output');
    var messages = monitorOutput.innerHTML.split('<br>');
    
    // Remove empty elements that may result from the last <br>
    messages = messages.filter(message => message.trim() !== '');
    
    if (messages.length > MAX_MESSAGES) {
        // Keep only the last MAX_MESSAGES messages
        var trimmedMessages = messages.slice(-MAX_MESSAGES);
        monitorOutput.innerHTML = trimmedMessages.join('<br>') + '<br>';
    }
}

document.getElementById('uploadForm').onsubmit = function(event) {
    event.preventDefault(); 

    var formData = new FormData(document.getElementById('uploadForm'));
    var xhr = new XMLHttpRequest();
    
    xhr.open('POST', '/upload', true);

    xhr.upload.onprogress = function(e) {
        if (e.lengthComputable) {
            var percentComplete = (e.loaded / e.total) * 100;
            var roundedProgress = Math.round(percentComplete);

            if (roundedProgress - lastSentProgress >= 10 || roundedProgress === 100) {
                var monitorOutput = document.getElementById('monitor-output');
                var currentTime = new Date().toLocaleTimeString();
                monitorOutput.innerHTML += `${currentTime} -> Progress: ${roundedProgress}%<br>`;
                limitMonitorMessages();
                document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
                lastSentProgress = roundedProgress;
            }
        }
    };

    xhr.onload = function() {
        var monitorOutput = document.getElementById('monitor-output');
        var currentTime = new Date().toLocaleTimeString();
        if (xhr.status == 200) {
            monitorOutput.innerHTML += `${currentTime} -> Update completed.<br>`;
        } else {
            monitorOutput.innerHTML += `${currentTime} -> Update failed.<br>`;
        }
        limitMonitorMessages();
        document.querySelector('.monitor-box').scrollTop = document.querySelector('.monitor-box').scrollHeight;
    };

    xhr.send(formData);
};

function sendDistanzValue() {
    var distanzValue = document.getElementById('distanz-input').value;
    if (socket && socket.readyState === WebSocket.OPEN) {
        socket.send(JSON.stringify({type: 'setDistanz', value: distanzValue}));
    } else {
        alert('WebSocket ist nicht verbunden.');
    }
}

function sendPinSettings() {
    var ledPin = document.getElementById('led-pin').value;
    var sclPin = document.getElementById('scl-pin').value;
    var sdaPin = document.getElementById('sda-pin').value;
    if (socket && socket.readyState === WebSocket.OPEN) {
        socket.send(JSON.stringify({
            type: 'setPins',
            ledPin: parseInt(ledPin),
            sclPin: parseInt(sclPin),
            sdaPin: parseInt(sdaPin)
        }));
    } else {
        alert('WebSocket ist nicht verbunden.');
    }
}

function sendWifiSettings() {
    var ssidValue = document.getElementById('wifi-ssid').value;
    var passwordValue = document.getElementById('wifi-password').value;

    // Passwortvalidierung: mindestens 8 Zeichen
    if (passwordValue.length < 8) {
        showToast('Passwort muss mindestens 8 Zeichen lang sein.', 'red');
        return;
    }

    if (socket && socket.readyState === WebSocket.OPEN) {
        socket.send(JSON.stringify({
            type: 'setWifi',
            ssid: ssidValue,
            password: passwordValue
        }));
    } else {
        alert('WebSocket ist nicht verbunden.');
    }
}

function showToast(message, color) {
    var toast = document.getElementById('toast');
    toast.innerText = message;
    if (color) {
        toast.style.backgroundColor = color;
    } else {
        toast.style.backgroundColor = '';  // Standardfarbe
    }
    toast.className = 'toast show';
    setTimeout(function() {
        toast.className = toast.className.replace('show', '');
        toast.style.backgroundColor = '';  // Zurücksetzen
    }, 3000);
}

function toggleNightMode() {
    document.body.classList.toggle('night-mode');
    var isNightMode = document.body.classList.contains('night-mode');
    document.cookie = "nightMode=" + (isNightMode ? "1" : "0") + ";path=/;max-age=31536000";
}

(function() {
    var nightModeCookie = document.cookie.split('; ').find(row => row.startsWith('nightMode'));
    if (nightModeCookie) {
        var isNightMode = nightModeCookie.split('=')[1] === "1";
        if (isNightMode) {
            document.body.classList.add('night-mode');
        }
    }
})();

// Heartbeat-Mechanismus
setInterval(function() {
    var currentTime = Date.now();
    if (currentTime - lastMessageTime > 5000) { // Wenn seit 5 Sekunden keine Nachricht empfangen wurde
        console.log("Keine Nachrichten in den letzten 5 Sekunden empfangen. Versuche, die Verbindung wiederherzustellen.");
        if (socket) {
            socket.close();
        }
        connectWebSocket();
    }
}, 5000);

window.onload = function() {
    setTimeout(connectWebSocket, 1000);
};
)rawliteral";
