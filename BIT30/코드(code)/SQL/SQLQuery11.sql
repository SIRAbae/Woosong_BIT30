--1) 학생 테이블--------------------------

CREATE TABLE [dbo].[Student](
	[SID] [varchar](50) NOT NULL,
	[SPW] [varchar](50) NOT NULL,
	[SNAME] [varchar](50) NOT NULL,
	[SGRADE] [int] NOT NULL,
	[SNUM] [int] NOT NULL,
	[SDEPT] [varchar](50) NOT NULL,
	[PHONE] [varchar](50) NOT NULL,
	[SIMG] [image] NOT NULL,
 CONSTRAINT [PK_Student] PRIMARY KEY CLUSTERED 
(
	[SNUM] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
 CONSTRAINT [Uni_Student] UNIQUE NONCLUSTERED 
(
	[SID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]


--2) 과목 테이블----------------------------

CREATE TABLE [Subject] (
    [SubID]    INT          IDENTITY (1, 1) NOT NULL,
    [SubName]  VARCHAR (30) NOT NULL,
    [StartDay] DATE         NOT NULL,
    [EndDay]   DATE         NOT NULL,
    PRIMARY KEY CLUSTERED ([SubID] ASC)
);

--3) 성적 테이블----------------------
CREATE TABLE dbo.Score
	(
	SCORINDEX int NOT NULL IDENTITY (1, 1),
	SNUM int NOT NULL,
	SubID int NOT NULL,
	home_score int NOT NULL,
	Writing_scor int NOT NULL,
	Practical_scor int NOT NULL,
	date datetime NOT NULL

	CONSTRAINT [PK_SCORE] PRIMARY KEY CLUSTERED ([SCORINDEX] ASC),
    	CONSTRAINT [FK_SCORE_SID] FOREIGN KEY ([SNUM]) REFERENCES [dbo].[Student] ([SNUM]),
    	CONSTRAINT [FK_SCORE_SUBID] FOREIGN KEY ([SubID]) REFERENCES [dbo].[Subject] ([SubID])

	)

--4) 조 테이블
CREATE TABLE [dbo].[Team] (
    [TID]        INT           IDENTITY (1, 1) NOT NULL,
    [Tstartdate] DATETIME      NULL,
    [Tenddate]   DATETIME      NOT NULL,
    [Tname]      VARCHAR (50) NULL,
    CONSTRAINT [PK_Team] PRIMARY KEY CLUSTERED ([TID] ASC)
);

--5)조 편성테이블
CREATE TABLE [dbo].[Organization] (
    [OID]  INT IDENTITY (1, 1) NOT NULL,
    [TID]  INT NOT NULL,
    [SNUM] INT NOT NULL,
    CONSTRAINT [PK_Organization] PRIMARY KEY CLUSTERED ([OID] ASC),
    CONSTRAINT [FK_Organization_STUDENT] FOREIGN KEY ([SNUM]) REFERENCES [dbo].[Student] ([SNUM]),
    CONSTRAINT [FK_Organization_TEAM] FOREIGN KEY ([TID]) REFERENCES [dbo].[Team] ([TID])
);


--6)출석 테이블
CREATE TABLE Attend(
   AID int IDENTITY(1,1) NOT NULL,
   SNUM int NOT NULL,
   ADATE date NOT NULL,
   ATIME varchar(10) NOT NULL check(ATIME IN ('오전', '오후', '저녁')) ,
   ACHECK varchar(10) NOT NULL check(ACHECK IN ('출석', '결석', '지각')),
 CONSTRAINT [PK_Attend] PRIMARY KEY CLUSTERED 
(
   AID ASC
))
 ALTER TABLE [Attend] ADD CONSTRAINT [SNUM] FOREIGN KEY ([SNUM]) REFERENCES [Student] ([SNUM])







DROP TABLE Attend;
DROP TABLE Organization;
DROP TABLE Team;
DROP TABLE Score;
DROP TABLE Subject;
DROP TABLE Student;






Insert INTO Subject  Values ('Win32','2019-08-26','2019-09-05');




insert into Student(SID,SPW,SNAME,SGRADE,SNUM,SDEPT,PHONE,SIMG)
select 'sdfsada','1234','김경훈',3,201510042,'글철','01028795586',null
--from openrowset(bulk N'C:\Users\USER\Desktop\성적_학생 수정ui',single_blob) AS pic;

INSERT INTO dbo.Score (SNUM , SubID, home_score, Writing_scor, Practical_scor, Date) 
VALUES (201510044, 1, '100','30','20', '2019-08-26')

select stu.* 
from Student stu, Subject sub, Score sco 
where snum = '201510042' and SUBNAME= Win32;


