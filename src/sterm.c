/* Entry point and program event loop
 * Author: Salvatore Termine
 * Date: 08/05/17
 */
#include "../include/sterm.h"

int main(int argc, char** argv) {
	// PROGRAM LOOP
	sterm_loop();
	// RETURN SUCCESS ON EXIT
	return EXIT_SUCCESS;
}