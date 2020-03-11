//data.h

//typedef struct tagTeam
//{
//	int team_id;
//	TCHAR team_name[50];
//}TEAM;

typedef struct tagTeam
{
	int cus_id;
	TCHAR cus_name[30];
	TCHAR cus_phone[30];
	TCHAR cus_date[50];
	TCHAR cus_gender[30];
}TEAM;

typedef struct tagAccName
{
	TCHAR cus_name[30];
	
}AccName;

typedef struct tagAccData
{
	int acc_id;
	int acc_val;
	int acc_count;
	int cus_id;
	
	TCHAR acc_date[50];

}AccData;