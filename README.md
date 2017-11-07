## Commands

```
add <variable type> <variable name> <variable data>
``` - adds a new variable of the chosen type and fills it with the variable data
  Variable types are:
  + **area** - parameters are <dim> <left> <right> <left> <right> ... <left> <right> (*dim* times)
  + **point** / **pt** - parameters are <dim> <coordinates (*dim* numbers)>
  + **method** - parameters are <method type> <method parameters>
    Options for method type are:
    - **nelder** - Nelder-Mead method. Parameters are <reflectrion> <contraction> <expansion> <shrink> (See [] for information about the method and its parameters)
    - **random** - Random Search method. Parameters are <p> <gamma>.
