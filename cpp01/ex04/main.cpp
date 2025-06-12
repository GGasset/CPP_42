
#include "replace.h"

int main(int argc, char *argv[])
{
	if (argc != 4) { 
		std::cout << "Usage: ./replace filename s1 s2" << std::endl; return 0; 
	}

	if (argv[2][0] == 0 || argv[2][0] == 0) {
		std::cout << "Error: s1 and s2 must not be an empty string" << std::endl;
		return 0;
	}

	std::ifstream instream(argv[1]);
	if (!instream.good()) {
		std::cout << "Error opening infile: " << argv[1] << std::endl;
		return 0;
	}
	std::stringstream infile_contents_buffer;
	infile_contents_buffer << instream.rdbuf();
	instream.close();

	std::string infile = infile_contents_buffer.str();
	std::string out_contents = cpp_replace(infile, argv[2], argv[3]);

	std::string outfile = argv[1];
	outfile.append(".replace");

	std::ofstream outstream;
	outstream.open(outfile.c_str(), std::ofstream::trunc);

	if (!outstream.good())
	{
		std::cout << "Error opening outfile: " << outfile << std::endl;
		return 0;
	}
	outstream << out_contents;
}
