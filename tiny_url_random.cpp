#include<bits/stdc++.h>
using namespace std;
const int size=6;
const string allpossible="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
class Database
{
private:
	unordered_set<string> shortu;
public:
	bool exists(string &shorturls)
	{
		return shortu.find(shorturls) != shortu.end();
	}
	void insert(string &shorturls)
	{
		shortu.insert(shorturls);
	}
};
bool checkShortLinkExists(string& shorturl, Database& db) {
    return db.exists(shorturl);
}
string generateRandomURL(Database &db)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> v(0, allpossible.size() - 1);
	while(true)
	{
		string shorturl;
		for (int i=0;i<size;i++)
		{
			int random=v(generator);
			shorturl+=allpossible[random];
		}
		if (!db.exists(shorturl))
		{
			//db.insert(shorturl);
			return shorturl;
		}
	}
}
int main()
{
	Database db;
	string shorturl=generateRandomURL(db);
	cout<<"Short URL: "<<shorturl<<'\n';
	return 0;
}