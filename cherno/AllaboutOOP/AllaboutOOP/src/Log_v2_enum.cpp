#include <iostream>


class Log {
public:
	enum Level {
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo;
public:
	void setLevel(Level lvl) {
		m_LogLevel = lvl;
	}
	void Err(const char* msg) {
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR] :" << msg << std::endl;
	}
	void Warn(const char* msg) {
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING] :" << msg << std::endl;
	}
	void Info(const char* msg) {
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO] :" << msg << std::endl;
	}
};

int l2main() {
	/*
	* Logging sys has 3 levels
	* 1.ERROR
	* 2.WARNING
	* 3.MSG
	*
	* if we set to MSG all 3 works
	* elif we set to WARN only warn and err works
	* else we only get errs
	*/
	Log log;
	log.setLevel(Log::LevelWarning);
	log.Warn("Forgot to turn off Lights !");
	log.Info("Room is not clean.");
	log.Err("Forgot to turn off Gas !!!");
	Log log2;
	log2.Warn("Forgot to turn off Lights !");
	log2.Info("Room is not clean.");
	log2.Err("Forgot to turn off Gas !!!");
	return 0;
}