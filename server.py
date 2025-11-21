from http.server import BaseHTTPRequestHandler, HTTPServer
import subprocess

class Handler(BaseHTTPRequestHandler):
    def do_POST(self):
        length = int(self.headers['Content-Length'])
        word = self.rfile.read(length).decode()

        # call the C++ spell checker
        result = subprocess.run(
            ["./spell"],
            input=word.encode(),
            stdout=subprocess.PIPE
        ).stdout.decode()

        # send result back to browser
        self.send_response(200)
        self.send_header("Content-Type", "text/plain")
        self.end_headers()
        self.wfile.write(result.encode())

server = HTTPServer(("0.0.0.0", 8080), Handler)
print("Server running on http://localhost:8080")
server.serve_forever()
