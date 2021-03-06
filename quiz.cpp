#include "quiz.h"

Quiz::Quiz() {
	quiz_id = -1;
}

Quiz::Quiz(string quizname, string questionids, string subject) {
	this->quizname = quizname;
	this->questionids = questionids;
	this->subject = subject;
}

int Quiz::getQuiz_id() {
	return quiz_id;
}

void Quiz::setQuiz_id(int quiz_id) {
	this->quiz_id = quiz_id;
}

string Quiz::getQuizname() {
	return quizname;
}

void Quiz::setQuizname(string quizname) {
	this->quizname = quizname;
}

string Quiz::getQuestionids() {
	return questionids;
}

void Quiz::setQuestionids(string questionids) {
	this->questionids = questionids;
}

string Quiz::getSubject() {
	return subject;
}

void Quiz::setSubject(string subject) {
	this->subject = subject;
}

void Quiz::getQuizList(){
	try {
		mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
		sql::Connection *DBcon = Conn->Connect();
		sql::PreparedStatement *prep_stmt;
		sql::ResultSet *res;
		string SQL = "SELECT * FROM quiz";
		prep_stmt = DBcon->prepareStatement(SQL);
		res = prep_stmt->executeQuery();
		cout << "Quizlist are: " << endl;
		while (res->next()) {
			cout << res->getString("quizname") << ", Question IDs: " << res->getString("question_id") << endl;
		}
		cout << endl;
		DBcon->close();
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	return;
}

void Quiz::getQuiz(string args){
	try {
      if (!checkExist(args))
        return;

		mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
		sql::Connection *DBcon = Conn->Connect();
		sql::PreparedStatement *prep_stmt;
		sql::ResultSet *res;

		string SQL = "SELECT * FROM quiz where quizname =?";
		prep_stmt = DBcon->prepareStatement(SQL);
		prep_stmt->setString(1,args);
		res = prep_stmt->executeQuery();
		if(res->next()) {
			setQuiz_id(res->getInt("quiz_id"));
			setQuizname(res->getString("quizname"));
			setQuestionids(res->getString("question_id"));
			setSubject(res->getString("subject"));
		}
        else{
          cout << "No quiz " << args << endl;
        }
		cout << endl;
		DBcon->close();
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	return;
}

string Quiz::getQuestions(string subject) {
	//Not used
	return "";
}

void Quiz::createquiz() {
	try {
		mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
		sql::Connection *DBcon = Conn->Connect();
		sql::PreparedStatement *prep_stmt;
		int res;
		string SQL = "INSERT INTO quiz (quizname, question_id, subject) VALUES (?, ?, ?)";
		prep_stmt = DBcon->prepareStatement(SQL);
		prep_stmt->setString(1, quizname);
		prep_stmt->setString(2, questionids);
		prep_stmt->setString(3, subject);
		res = prep_stmt->executeUpdate();
		if (res > 0) {
			cout << "Quiz Created!" << endl;
            cout << endl;
		}
        else{
          cout << "Something went very wrong with creating a quiz." << endl;
          cout << endl;
        }
		DBcon->close();
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	//main.quizName = subject ??
	return;
}

bool Quiz::checkExist(string subject) {
	try {
		mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
		sql::Connection *DBcon = Conn->Connect();
		sql::PreparedStatement *prep_stmt;
		sql::ResultSet *res;
		string SQL = "SELECT * FROM quiz where quizname = ?";
		prep_stmt = DBcon->prepareStatement(SQL);
        prep_stmt->setString(1, subject);
		res = prep_stmt->executeQuery();

		bool val = res->next();
		if (val == false) {
			cout << "Quiz name does not exist!" << endl;
			return false;
		}
		else if (val) {
			cout << "Quiz name does exist!" << endl;
			return true;
		}

		DBcon->close();
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	return false;
}

void Quiz::setUpdateQuizName(string subject, string mainQuizName) {
	try {
		mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
		sql::Connection *DBcon = Conn->Connect();
		sql::PreparedStatement *prep_stmt;
		int res;
		string SQL = "UPDATE quiz set subject = ?, quizname = ? where (subject = ?)";
		prep_stmt = DBcon->prepareStatement(SQL);
		prep_stmt->setString(1, subject);
		prep_stmt->setString(2, subject);
		prep_stmt->setString(3, mainQuizName);
		res = prep_stmt->executeUpdate();
		if (res > 0) {
			cout << "Quiz name updated!" << endl;
			Questions q;
			q.updateSubject(subject, mainQuizName);
			//main.quizName = subject;
			setSubject(subject);
		}
		DBcon->close();
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	return;
}

void Quiz::cleanupQuiz() {
	try {
		mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
		sql::Connection *DBcon = Conn->Connect();
		sql::PreparedStatement *prep_stmt;
		sql::ResultSet *res;
		res = DBcon->createStatement()->executeQuery("SET @num := 0; UPDATE quiz SET quiz_id = @num := (@num+1)");
		DBcon->close();
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}

	return;
}

void Quiz::deleteQuiz(string quiz_id, string mainQuizName) {
	try {
		mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
		sql::Connection *DBcon = Conn->Connect();
		sql::PreparedStatement *prep_stmt;
		int res;
		string SQL = "DELETE FROM quiz WHERE subject = ?";
		prep_stmt = DBcon->prepareStatement(SQL);
		prep_stmt->setString(1, quiz_id);
		res = prep_stmt->executeUpdate();
		if (res > 0) {
			cleanupQuiz();
			Questions q;
			q.deleteQuestions(mainQuizName);
			cout << "Quiz " << mainQuizName << " deleted!" << endl;
			//main.quizName = "";
		}
		DBcon->close();
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	return;
}
const string &Quiz::getAllquiz() const {
	return allquiz;
}
void Quiz::setAllquiz(const string &allquiz) {
	Quiz::allquiz = allquiz;
}

void Quiz::linkQuestion(string subject1, string qid){
  try {
    mysqlconnector *Conn = new mysqlconnector("127.0.0.1", "1009", "root", "");
    sql::Connection *DBcon = Conn->Connect();
    sql::PreparedStatement *prep_stmt;
    int res;
    string SQL = "UPDATE quiz set question_id = ? where (subject = ?)";
    prep_stmt = DBcon->prepareStatement(SQL);
    prep_stmt->setString(1, qid);
    prep_stmt->setString(2, subject1);
    res = prep_stmt->executeUpdate();
    if (res > 0) {
      cout << "Question IDs updated " << qid << " for quiz: " << subject1 << std::endl;
    }
    DBcon->close();
  }
  catch (sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
  }
  return;
}