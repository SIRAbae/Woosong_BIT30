USE [wb30]
GO

/****** Object:  Table [dbo].[Student]    Script Date: 10/08/2019 22:04:08 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[Student](
	[SID] [varchar](50) NOT NULL,
	[SPW] [varchar](50) NOT NULL,
	[SNAME] [varchar](50) NOT NULL,
	[SGRADE] [int] NOT NULL,
	[SNUM] [int] NOT NULL,
	[SDEPT] [varchar](50) NOT NULL,
	[PHONE] [varchar](50) NOT NULL,
	[SIMG] [image] ,
 CONSTRAINT [PK_Student] PRIMARY KEY CLUSTERED 
(
	[SNUM] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY],
 CONSTRAINT [Uni_Student] UNIQUE NONCLUSTERED 
(
	[SID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO


