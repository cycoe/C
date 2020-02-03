typedef struct {
  short zone;
  short exchange;
  short station;
} TELE_NUMBER;

typedef struct {
  short year;
  short month;
  short day;
  int time;
  TELE_NUMBER called;
  TELE_NUMBER calling;
  TELE_NUMBER billed;
} RECORD;
