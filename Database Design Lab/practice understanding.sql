SELECT B.AUTHOR,COUNT(B.POST),COUNT(C.COMMENT)
FROM friendbook_sizepost B,friendbook_comment C
WHERE B.ID=C.POST
GROUP BY B.AUTHOR
/* to get all comments and all posts of all author*/
/*
SELECT A.NAME
FROM friendbook_author A
WHERE A.ID IN(  SELECT B.AUTHOR
				FROM friendbook_sizepost B
				GROUP BY B.AUTHOR
				ORDER BY COUNT(B.POST))*/


SELECT A.NAME
FROM friendbook_sizepost B,friendbook_author A
WHERE B.AUTHOR=A.ID
GROUP BY B.AUTHOR,A.NAME
ORDER BY COUNT(B.AUTHOR) ASC