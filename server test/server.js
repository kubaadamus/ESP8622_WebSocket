var WebSocketServer = require('ws').Server,
 wss = new WebSocketServer({port: 80});
 console.log("Serwer Stoi!");
wss.on('connection', function(ws) {
 console.log('client connected');
 ws.on('message', function(message) {
 console.log(message);
 });
});

wss.onupgrade = function(request, socket) {
    var key = request.headers['sec-websocket-key'];
    key = require('crypto').createHash('sha1').update(key+"258EAFA5-E914-47DA-95CA-C5AB0DC85B11").digest('base64');
    
    var sResponse = "HTTP/1.1 101 Switching Protocols\r\n" +
        "Upgrade: websocket\r\n" + "Connection: Upgrade\r\n" +
        "Sec-WebSocket-Accept: " + key + "\r\n\r\n";
        socket.write(sResponse,'ascii');
    
    //...
    }