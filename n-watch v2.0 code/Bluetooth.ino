void initBL()
{
  SerialBT.register_callback(callback);
  SerialBT.begin("n-watch v2.0");
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param)
{
  if (event == ESP_SPP_SRV_OPEN_EVT)
  {
    Serial.println ("Client Connected");
    conected = true;
  }
  else if (event == ESP_SPP_CLOSE_EVT)
  {
    Serial.println ("Client Disconnected");
    conected = false;
  }
}
