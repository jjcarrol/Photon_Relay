/**
 *  Spark Core
 *
 *  Copyright 2015 TOM FORTI
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
 *  in compliance with the License. You may obtain a copy of the License at:
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software distributed under the License is distributed
 *  on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License
 *  for the specific language governing permissions and limitations under the License.
 *
 */
/**
 *  PHOTON RELAY
 *
 *  Author: tomforti@gmail.com
 *  Date: 2015-10-18
 *
 *  Modified: knighti.1975@gmail.com
 *  Date: 2017-04-01
 */
 
 
preferences {
    input("token", "text", title: "Access Token")
    input("deviceId", "text", title: "Device ID")
    input("relaynum", "text", title: "Relay Number 1-6")
    
}


 
 // for the UI
metadata {
	definition (name: "PHOTON RELAY", author: "tonforti@gmail.com") {
    	capability "Switch"
        capability "Polling"
	}

    // tile definitions
    tiles(scale: 2) {
          
	standardTile("switch", "device.switch", width: 2, height: 2, canChangeIcon: true) {
	state "on", label: '${name}', action: "switch.off", icon: "st.switches.switch.on", backgroundColor: "#79b821"
	state "off", label: '${name}', action: "switch.on", icon: "st.switches.switch.off", backgroundColor: "#ffffff"
         state "offline", label:'${name}', action: "switch.off", icon:"st.switches.switch.off", backgroundColor:"#ff0000"
		}

		main "switch"
		details "switch" 
	}
    

}

def initialize (){
state.swipos = 0

}

def parse(String description) {
	log.error "This device does not support incoming events"
	return null
}

def on() {
	put '1'
   state.swipos = 1
   log.debug "Switch on"
    sendEvent(name: 'switch', value: 'on')
}

def off() {
	put '0'
   state.swipos = 0
   log.debug "Switch off"
    sendEvent(name: 'switch', value: 'off')
}

def offline() {
  state.swipos = 2
   log.debug "offline"
   sendEvent(name: "switch", value: "offline", descriptionText: "The device is offline")
}

private put(relaystate) {
    //Spark Core API Call
	httpPost(
		uri: "https://api.spark.io/v1/devices/${deviceId}/strelay${relaynum}",
        body: [access_token: token, command: relaystate],  
	) {response -> log.debug (response.data)}
}
private get(state) {
    //Spark Core API Call
    //log.debug "https://api.spark.io/v1/devices/${deviceId}/r${relaynum}?access_token=${token}"
try {	
    httpGet(
		uri: "https://api.spark.io/v1/devices/${deviceId}/r${relaynum}?access_token=${token}"  
	) {response -> 
    log.debug "Actual Core ${response.data.result}"
    log.debug "App Swipos ${state.swipos}"
 if (response.data.result == state.swipos){
      log.debug "Switch possition ok"
 }
 else
 {
 	if (response.data.result == 1){
    on()
    log.debug "GO to Match actual state - Switch On "
    }
    else
    {
    off()
     log.debug "Goto Match actual state - Switch Off "
    }
 
 
 }
 }   
 }
 catch (e) {
 
 log.debug "Error offline'"
 log.debug e
 offline()
 }
}

def poll() {
	log.debug "Executing 'poll'"
   get(state)
 

}

