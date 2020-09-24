#include <iostream>

using namespace std;

//! Template for function header, DO NOT TOUCH
/******************************************************
** Function: 
** Description: 
** Parameters: NA
** Pre-conditions: NA
** Post-conditions: NA
******************************************************/

/******************************************************
** Function: error_handle_cmd_line
** Description: Error handles the command line arguments
** before it continues.
** Parameters: string &, string &
** Pre-conditions: Take in the command line arguments as
** string references.
** Post-conditions: Return the corrected arguments after
** handling.
******************************************************/

void error_handle_cmd_line(string &, string &);

/******************************************************
** Function: is_int
** Description: Simple custom error handling of a string
** to show if its a valid integer.
** Parameters: string
** Pre-conditions: Take in a string to test.
** Post-conditions: Unchanged, returns a boolean to 
** show if it is a valid integer.
******************************************************/

bool is_int(string);