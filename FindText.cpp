#include "FindText.h"
#define E ".!?"
#define D " ,:;"
FindText::FindText()
{

	std::string path = "MeText.txt", line = "",str = "";
	std::fstream f;
	f.open(path);

	if (f.is_open()) {
		while (getline(f, line, '\0'))
	
			str += find(line);
		
		f.close();
		std::cout<<"--------------------------\n";
		std::cout << str;
		std::cout << "--------------------------\n";
	}
	else
		std::cout << "file wasn't open\n";

}

std::string FindText::find(std::string line)
{
	char c, prev;
	int i = 0, pos1=0,pos2=0;
	bool sign = true;
	std::string out = "";
	while (line[i] != '\0') {
		c = line[i];
		if (c == D[0] || c == D[1] || c == D[2] || c == D[3] || c == E[0] || c == E[1] || c == E[2]) {
			//разделитель
			if (c == E[0] || c == E[1] || c == E[2]) {
				//конец предложения
				pos2 = i;
				if (sign)
					out += line.substr(pos1, pos2 + 1 - pos1 + 1)+"\n";
				
			}
			else if(c==D[1])
				sign = false;
			
		}
		else{
			if (i != 0) {
				if (i >= 2) {
					if ((line[i - 1] == D[0] || line[i - 1] == D[1] || line[i - 1] == D[2] || line[i - 1] == D[3]|| line[i - 1] == '\n')
						&& (line[i - 2] == E[0]
							|| line[i - 2] == E[1] || line[i - 2] == E[2])) {

						pos2 = i;
						pos1 = i;
						sign = true;
					}
				}
			}
		}

		i++;
	}

	return std::string(out);
}
