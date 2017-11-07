# Commands

List of commands:
* ``` add <variable type> <variable name> <variable data>```  - adds new variable
* ``` get <variable type> <variable name>```  - shows information about an existing variable
* ``` rm <variable name>```  - deletes an existing variable
* ``` opt <fn> <area> <method> <cond> <pt> [res]```  - runs optimization process
* ``` test```  - writes 'test OK'

## Command *get*
Syntax: ```get <variable type> <variable name>```...
Variable type options are:
* **_function_** (also **_fun_**, **_fn_** ) - returns information about an existing function variable
  + Existing function variables: **_f1_**, **_f2_**, **_f3_**, **_f4_**, **_f5_**
* **_area_**  - returns information about an existing area variable
* **_method_** -  - returns information about an existing optimization method variable
* **_condition_** (also **_cond_**)  - returns information about an existing terminal condition variable
* **_point_** (also **_pt_**)  - returns information about an existing vector point variable
