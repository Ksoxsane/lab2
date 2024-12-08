#include "second.h"
SentenceFilter::SentenceFilter() : source(""), count(0), isTextSource(false)
{
    cout << "The constructor is called without parameters for the SentenceFilter class\n";
}
SentenceFilter::SentenceFilter(const string& filename, int count) : source(filename), count(count), isTextSource(false) {
    cout << "The constructor is called with parameters for the SentenceFilter class\n";
}
SentenceFilter::SentenceFilter(const string& text, int count, bool isText) : source(text), count(count), isTextSource(isText) {
    cout << "The constructor is called with parameters for the SentenceFilter class\n";
}
SentenceFilter::SentenceFilter(const SentenceFilter& other) : source(other.source), count(other.count),
isTextSource(other.isTextSource) {
    cout << "The copy constructor for the SentenceFilter class is called\n";
}
SentenceFilter::~SentenceFilter() {
    cout << "The destructor for the SentenceFilter class is called\n";
}
void SentenceFilter::result() const {
    string text;

    if (isTextSource) {
        text = source;
    } 
    else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "Error: " << source << endl;
            return;
        }
        ostringstream buffer;
        buffer << file.rdbuf();
        text = buffer.str();
        file.close();
    }
    cout << "Your text:\n" << text << "\n\n";
    string* sentences = nullptr;
    int sentenceCount = 0;
    split_into_sent(text, sentences, sentenceCount);
    cout << "Amount of sentences: " << sentenceCount << endl;
    for (int i = 0; i < sentenceCount; ++i) 
    {
        int words = count_words(sentences[i]);
        if (words == count) {
            cout << sentences[i] << endl;
        }
    }
    delete[] sentences;
}
void SentenceFilter::split_into_sent(const string& text, string*& sentences,
int& sentenceCount) const {
    const int maxSentences = 100;
    sentences = new string[maxSentences];
    sentenceCount = 0;
    ostringstream sentenceStream;
    for (char ch : text) {
        sentenceStream << ch;
        if (ch == '.' || ch == '!' || ch == '?') {
            if (sentenceCount < maxSentences) {
                sentences[sentenceCount++] = sentenceStream.str();
                sentenceStream.str("");
                sentenceStream.clear();
            }
        }
    }
    if (!sentenceStream.str().empty() && sentenceCount < maxSentences) {
        sentences[sentenceCount++] = sentenceStream.str();
    }
}
int SentenceFilter::count_words(const string& sentence) const {
    int count = 0;
    istringstream ss(sentence);
    string word;
    while (ss >> word) {
    ++count;
    }
    return count;
}
