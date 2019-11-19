# include <iostream>

const char SEP_CHAR = '-';
const size_t SEP_FILL = 80;
std::cout <<"\e[2m" <<
		std::setfill(SEP_CHAR) <<
		std::setw(SEP_FILL) <<
		"\e[0m" <<
		"\n";

return 0;