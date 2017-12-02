#ifndef HIGHSCORES_H
#define HIGHSCORES_H
class HighScores
{
public:
	int readScores();
	int writeScores(int score);
	HighScores();
	~HighScores();
};

#endif