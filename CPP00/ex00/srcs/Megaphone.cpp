#include <iostream>

class Megaphone
{
	private:
		char		**phrases;
		const char	*default_phrase;
		int			amt_phrases;
	public:
		Megaphone(int argc, char *argv[])
		{
			this->phrases = argv + 1;
			this->amt_phrases = argc - 1;
			this->default_phrase = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		}
		~Megaphone(){
			this->phrases = NULL;
			this->default_phrase = NULL;
			this->amt_phrases = 0;
		}
		void onSound();
};

void Megaphone::onSound()
{
	int	i;
	int	j;

	if (this->amt_phrases > 0)
	{
		i = 0;
		while (i < this->amt_phrases)
		{
			j = 0;
			while (this->phrases[i][j])
			{
				std::cout << (char)std::toupper(this->phrases[i][j]);
				j++;
			}
			i++;
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << this->default_phrase << '\n';
	}
}

int main(int argc, char *argv[])
{
	Megaphone myMegaphone(argc, argv);
	myMegaphone.onSound();
    return 0;
}