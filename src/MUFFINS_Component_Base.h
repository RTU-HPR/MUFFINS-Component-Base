#pragma once
#include <Arduino.h>

class Component_Base
{
  bool _initialized;
  String _name;
  void (*_info_function)(String);
  void (*_error_function)(String);
  void _set_info_output_function(void (*info_function)(String)) { _info_function = info_function; }
  void _set_error_output_function(void (*error_function)(String)) { _error_function = error_function; }

public:
  /**
   * @brief Construct a new Component Base object
   */
  Component_Base(String component_name, void (*info_function)(String) = nullptr, void (*error_function)(String) = nullptr);

  /**
   * @brief Set the info output function object. If not set by default info will be output in serial port.
   * Note that if the function is inside a class then passing it to the set info output might be difficult
   *
   * @param func pointer to a function that you can pass the info string
   */
  void info(String msg);

  /**
   * @brief Set the error output function object. If not set by default error will be output in serial port.
   * Note that if the function is inside a class then passing it to the set error output might be difficult
   *
   * @param func pointer to a function that you can pass the error string
   */
  void error(String msg);

  /**
   * @brief Get the component name
  */
  String get_component_name() { return _name; }

  /**
   * @brief Set the component initialization status
  */
  void set_initialized(bool initialized) { _initialized = initialized; }

  /**
   * @brief Get the component initialization status
  */
  bool initialized() { return _initialized; }

};