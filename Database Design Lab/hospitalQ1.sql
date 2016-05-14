/* hospital many wards,each ward has many patients admitted on recommendation of their doctors 
and confirmed by a consultant from the hospital on admission all details are records.
A seperate register on admission,all details are recorded. A seperate register stores test info 
and results. Multiple tests can be performed on a patient and each patient can consult multiple doctors
Each doctor is a specialist on same branch of medicine and may be head consults for a number of patients
not necessarily from same ward.
Table + attributes
Insert statement 
Er diagram */

create table consultant(
name varchar(30),
id numeric(10) primary key NOT NULL,
);

create table patient(
name varchar(30),
gender varchar(20) check(gender in ('M','F')),
age numeric(10) NOT NULL,
id numeric(10) primary key NOT NULL,
confirm varchar(10) check(confirm in('y','n')),
wardroom numeric(10),
con numeric references consultant(id),
);

create table doctor(
name varchar(30),
id numeric(10) primary key NOT NULL,
branch varchar(20) NOT NULL,
gender varchar(20) check(gender in ('M','F')),
age numeric(10) NOT NULL,
patientid numeric references patient(id),
type varchar(10) check (type in ('D','H','C')) 
);

create table test(
id numeric(10) primary key NOT NULL,
result varchar check(result in('P','N')),
patientid numeric(10) references patient(id)
);

