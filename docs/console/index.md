---
generator: doxide
---


# Console Logger

Logs messages directly to the console.

## Functions

| Name | Description |
| ---- | ----------- |
| [error](#error) | For showing the user system error messages that will impact functionality. |
| [fatal](#fatal) | For alerting to an error that will completely halt the program or cause destructive behavior. |
| [info](#info) | For simple messages and notifications. |
| [init](#init) | Optional function to make sure Windows terminals will render colors. |
| [input](#input) | For prompting the user for input. |
| [warning](#warning) | For letting the user know about possible issues. |

## Function Details

### error<a name="error"></a>
!!! function "void   error(std::string&amp; msg)"

    For showing the user system error messages that will impact functionality.
        
    :material-location-enter: `msg`
    :    either an `e.what()` or a custom error message.
    

### fatal<a name="fatal"></a>
!!! function "void   fatal(std::string&amp; msg)"

    For alerting to an error that will completely halt the program or cause destructive behavior.
        
    :material-location-enter: `msg`
    :    either `e.what()` or a custom error message.
    

### info<a name="info"></a>
!!! function "void    info(std::string&amp; msg)"

    For simple messages and notifications.
    
    :material-location-enter: `msg`
    :    `std::string` to be displayed to the user.
    

### init<a name="init"></a>
!!! function "void init()"

    Optional function to make sure Windows terminals will render colors. Colors are enabled by default, but if the environment has them completely disabled, ANSI codes will render as gibberish.
    

### input<a name="input"></a>
!!! function "void   input(std::string&amp; msg)"

    For prompting the user for input. Adds '>>>' to let the user know its a pompt.
        
    :material-location-enter: `msg`
    :    `std::string` to be displayed to the user.
    

### warning<a name="warning"></a>
!!! function "void warning(std::string&amp; msg)"

    For letting the user know about possible issues.
        
    :material-location-enter: `msg`
    :    either an `e.what()` or a custom warning.
    

