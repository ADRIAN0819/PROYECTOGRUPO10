#ifndef UNTITLED19_MOVIESEARCHER_H
#define UNTITLED19_MOVIESEARCHER_H

#include <QString>
#include <QStringList>
#include <vector>
#include <map>
#include <mutex>

class MovieSearcher {
public:
    MovieSearcher(const QString &filePath);
    std::vector<QStringList> searchMovieByLetters(const QString &letters, int startIndex = 0);
    std::vector<QStringList> searchMovieByTags(const QString &tags, int startIndex = 0);
    QStringList getMovieDetails(const QString &title) const;
    QString getFirstTag(const QString &title) const;

private:
    QString filePath;
    std::map<QString, QStringList> movieData;
    std::mutex mutex;

    QStringList parseCSVLine(const QString &line);
    void readCSVFile();
};

#endif //UNTITLED19_MOVIESEARCHER_H
