/*
 GROUP-03
 HIMANSU RATHI 12/CS/06
 R OM PRAKASH 12/CS/07
*/

/* UPDATE  DATE COLUMN  IN POST AND COMMENT */
ALTER TABLE friendbook_sizepost
ADD DATES VARCHAR(20)

UPDATE friendbook_sizepost
SET DATES='10/09/14'
WHERE LEN(POST) <= 10
UPDATE friendbook_sizepost
SET DATES='11/09/14'
WHERE LEN(POST) > 10

ALTER TABLE friendbook_comment
ADD DATEC VARCHAR(20)

UPDATE friendbook_comment
SET DATEC='14/09/14'
WHERE LEN(COMMENT) <= 10
UPDATE friendbook_comment
SET DATEC='13/09/14'
WHERE LEN(COMMENT) > 10

/* QUERY 9*/
SELECT A.NAME,(SELECT B.POST FROM friendbook_sizepost B WHERE B.AUTHOR= D.AUTHOR ORDER BY A.DATES LIMIT 3,1) AS POST
FROM friendbook_sizepost D,friendbook_author A 
WHERE A.ID=D.AUTHOR AND A.AGE BETWEEN 45 AND 48 GROUP BY A.NAME 
HAVING COUNT( A.ID)>=5

/* QUERY 10 */
SELECT A.NAME,B.POST,B.ID,C.COMMENT
FROM friendbook_author A ,friendbook_comment C,friendbook_sizepost B
WHERE B.ID=C.POST  AND A.ID=B.AUTHOR AND (A.NAME='ISABELLA' OR A.NAME='ISABELLE')
 AND C.POST IN ( SELECT C.POST
				 FROM friendbook_comment C,friendbook_sizepost B
				 WHERE B.ID=C.POST 
				 GROUP BY C.POST
				 HAVING COUNT(C.POST)>=5)
ORDER BY B.ID
																											
/* QUERY 11 */
SELECT A.NAME
FROM friendbook_author A,friendbook_sizepost B
WHERE A.ID=B.AUTHOR
GROUP BY B.DATES,A.NAME
ORDER BY B.DATES ASC

SELECT A.NAME
FROM friendbook_author A,friendbook_sizepost B
WHERE A.ID=B.AUTHOR
GROUP BY B.DATES,A.NAME
ORDER BY B.DATES DESC

SELECT A.NAME
FROM friendbook_author A,friendbook_comment C
WHERE A.ID=C.AUTHOR
GROUP BY C.DATEC,A.NAME
ORDER BY C.DATEC ASC

SELECT A.NAME
FROM friendbook_author A,friendbook_comment C
WHERE A.ID=C.AUTHOR
GROUP BY C.DATEC,A.NAME
ORDER BY C.DATEC DESC

/* QUERY 12 */
SELECT AVG(A.AGE)
FROM friendbook_author A
WHERE A.GENDER='MALE' AND A.ID IN ( SELECT B.AUTHOR
									FROM friendbook_sizepost B
									WHERE LEN(B.POST) BETWEEN 40 AND 50 )

/* QUERY 13 */
SELECT A.NAME,A.ID,A.CITY,COUNT(B.POST),COUNT(C.COMMENT)
FROM friendbook_author A, friendbook_sizepost B,friendbook_comment C
WHERE A.CITY LIKE'K%'AND A.ID=B.AUTHOR AND C.POST=B.ID
GROUP BY A.ID,A.NAME,A.CITY
ORDER BY COUNT(B.POST) DESC, COUNT(C.COMMENT) DESC 