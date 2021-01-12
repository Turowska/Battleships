# Server

This server has been created using python 3. It utlizies socketio module that allows for a full-duplex connection between client and server<br>
which is necessary to send and recieve events by two parites in almost real-time.<br>
We also use gunicorn module that creates a WSGI HTTP server on which we run our socketio app.

### Running

In order to run the server we need all the requirements listed in requirements.txt.<br>
In the virtual enviorment (venv folder) all neccessary dependencies are already installed.<br>
To activate it run
''' shell
source venv/bin/activate
'
.<br>
Get into server directory and type

''' shell
gunicorn --threads 50 app:app
'''
to run it.
