const char* ACK_RESPONSE [6] PROGMEM = {
  "Command complete" , "Command disallow" , "Unknown command" , "Parameters error" , "BTM is busy" , "BTM memory is full" };

const char* SAMPLE_RATE [7] PROGMEM = {
  "8KHz" , "16KHz" , "32KHz" , "48KHz" , "44.1KHz" , "88KHz", "96KHz" };

const char* SAMPLE_RATE_MODE [9] PROGMEM = {
  "No Action" , "Prepare" , "Audio In Mode" , "PCM Mode" , "A2DP Decode Mode" , "SCO(HF) Mode" , "Tone" , "Voice Prompt" , "Reserved" };

const char* BTM_STATUS [22] PROGMEM = {
  "Power OSS state" , "Pairing state (discoverable mode)" , "Power ON state" , "Pairing successful" , "Pairing failed" ,
  "HS/HF Link Established" , "A2DP Link Established" , "HF Link disconnected" , "A2DP Link disconnected" , "SCO Link Connected" ,
  "SCO Link Disconnected" , "AVRCP link established" , "AVRCP link disconnected" , "Standard SPP connected" ,
  "Standard_SPP / iAP disconnected" , "Standby state" , "iAP connected" , "ACL disconnected" , "MAP connected" ,
  "MAP operation forbidden" , "MAP disconnected" , "ACL connected" };

const char* AUX_LINE_DETECT [4] PROGMEM = {
  "AUX Unplugged", "AUX Plugged In", "AUX Plugged In With Audio Signal", "AUX Plugged In Silent" };

const char* CHARGING_STATUS [5] PROGMEM = {
  "Charger is not plugged in." , "Charging" , "Charging Complete." , "Charging Failed" , "Charger type report." };

const char* AT_CMD_RSP [3] PROGMEM = {
  "AG response OK" , "AG response ERROR" , "No response from AG" };
