#include <Arduino.h>
#include <Component_Base.h>

class Example_Class : public Component_Base
{
public:
  Example_Class(String component_name = "Example Class", void (*info_function)(String) = nullptr, void (*error_function)(String) = nullptr);

  String example_function();
  void example_function_2();
  void example_function_3();
};

Example_Class::Example_Class(String component_name, void (*info_function)(String), void (*error_function)(String)) : Component_Base(component_name, info_function, error_function)
{
  // Constructor
}

String Example_Class::example_function()
{
  return get_component_name();
}

void Example_Class::example_function_2()
{
  info("Info message");
}

void Example_Class::example_function_3()
{
  error("Error message");
}

void setup()
{
  // Initialize Serial communication
  Serial.begin(115200);

  // Create an instance of the Example_Class
  Example_Class example_class;
  // Example_Class example_class("Example Class", nullptr, nullptr);

  // Call the example_function
  Serial.println(example_class.example_function());

  // Call the example_function_2
  example_class.example_function_2();

  // Call the example_function_3
  example_class.example_function_3();
}

void loop()
{
  // Empty
}