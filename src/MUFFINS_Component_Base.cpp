#include <MUFFINS_Component_Base.h>

Component_Base::Component_Base(String component_name, void (*info_function)(String), void (*error_function)(String))
{
  _name = component_name;
  _info_function = info_function;
  _error_function = error_function;
}

void Component_Base::info(String msg)
{
  msg = "Time ON: " + String(millis()) + "| " + _name + " Info: " + msg;

  if (_info_function == nullptr)
  {
    Serial.println(msg);
  }
  else
  {
    _info_function(msg);
  }
}

void Component_Base::error(String msg)
{
  msg = "Time ON: " + String(millis()) + "| " + _name + " Error: " + msg;

  if (_error_function == nullptr)
  {
    Serial.println(msg);
  }
  else
  {
    _error_function(msg);
  }
}