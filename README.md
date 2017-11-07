# Commands

List of commands:
* `add <variable type> <variable name> <variable data>`  - adds new variable
* ` get <variable type> <variable name>`  - shows information about an existing variable
* ` rm <variable name>`  - deletes an existing variable
* ` opt <fn> <area> <method> <cond> <pt> [res]`  - runs optimization process
* ` test`  - writes 'test OK'

## Command *get*
Syntax: `get <variable type> <variable name>`

Variable type options are:
* **_function_** (also **_fun_**, **_fn_** ) - returns information about an existing function variable
  + Existing function variables: **_f1_**, **_f2_**, **_f3_**, **_f4_**, **_f5_**
* **_area_**  - returns information about an existing area variable
* **_method_** -  - returns information about an existing optimization method variable
* **_condition_** (also **_cond_**)  - returns information about an existing terminal condition variable
* **_point_** (also **_pt_**)  - returns information about an existing vector point variable

Examples: `get fn f1`, `get area myarea`

## Command *add*
Syntax: `add <variable type> <variable name> <variable data>`

For variable type options see **Command** **_get_** (excluding **_function_**)

### Adding new area
Syntax: `add area <area name> <dim> <left> <right> ... <left> <right>`

`<dim>` - dimension of the area
`<left> <right>` x _dim_ - left and right bounds of the ranges of the area

Examples:
* `add area a1 2 -10 10 -5 5` - adds a two-dimensional area (-10; 10) x (-5; 5)
* `add area a2 2 -1 1 -2 2 -3 3` - adds a three-dimensional area (-1; 1) x (-2; 2) x (-3; 3)

### Adding new method
Syntax: `add method <variable name> <type> <parameters>

Options for method type are:
* **_nelder_** - Nelder-Mead method. Syntax is `add method <variable name> nelder <reflection> <expansion> <contraction> <shrink>` (See [] for the algorithm parameters clarification).
* **_random_** - Random Search method. Syntax is `add method <variable name> random <p> <gamma>`

Examples:
* `add method nm nelder 1 2 0.5 0.5`
* `add method rs random 0.5 0.25`

### Adding new condition
Syntax: `add cond <variable name> <type> <param>`

Options for condition type are:
* **_iter_** - Stop after a certain number of iterations. Syntax: `add cond it iter <N>`
* **_improvement_** (also **_improve_**) - Stop after failing to improve the result after a certain number of iterations. Syntax: `add cond imp improve <N>`
* **_grad_** - Stop if gradient value is less than <param>. Syntax: `add cond g grad <eps>`
* **_xdiff_** - Stop if ||X_{n} - X_{n-1}|| < <param>, where X_{n}, X_{n-1} are two last approximations.
Syntax: `add cond dx xdiff <eps>`
* **_fdiff_** - Stop if ||f(X_{n}) - f(X_{n-1})|| < <param>, where X_{n}, X_{n-1} are two last approximations.
Syntax: `add cond df fdiff <eps>`

### Adding new point
Syntax: `add pt <variable name> <dim> <coord_1> <coord_2> ... <coord_dim>`

* `<dim>` - the dimension of the point
* `<coord_1> <coord_2> ... <coord_dim>` - coordinates of the point ( _dim_ numbers)

## Command _opt_
` opt <fn> <area> <method> <cond> <pt> [res]` - runs the optimization process

Parameters:
* `<fn>` - function variable name
* `<area>` - area variable name
* `<method>` - optimization method variable name
* `<cond>` - terminal condition variable name
* `<pt>` - first point variable name
* `[res]` - (optional) variable to which the result of optimization is saved

## Command _rm_
Syntax: `rm <variable name>` - deletes a variable

## Command _test_
Syntax: `test` - returns 'test OK'
