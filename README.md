# Photon_Relay2
Allows Smartthings to control a Particle Photon (spark core) as a 8 relay switch, (included polling states, and detecting if core is offline)

To set up 
1. Put the INO code on your Photon
2. Put the Groovy code as a device type on smartthings
3. Add a new deivce and use the newly made device type
4. In preferences of the new device add you photons token and device ID
5. In preferences tell smartthings which relay it will control.
6. Code is all setup for use with eagle relay board see zip file for eagle board. 

You will need to use Pollster - The SmartThings Polling Daemon, Please visit [https://github.com/statusbits/smartthings] in order to poll the status of the relays, as polling in Smartthing is unreliable. 
