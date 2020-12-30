-- 练习题目
-- 1. 查询" 01 "课程比" 02 "课程成绩高的学生的信息及课程分数
SELECT * FROM student INNER JOIN (
    SELECT t1.sid, t1.class1, t2.class2 FROM
    (SELECT sid, score as class1 FROM SC WHERE CId='01') as t1,
    (SELECT sid,score as class2 FROM sc WHERE CId='02') as t2
    WHERE t1.sid=t2.sid AND t1.class1 > t2.class2
)r
ON student.sid=r.sid;

-- 1.1 查询同时存在" 01 "课程和" 02 "课程的情况
SELECT * FROM 
    (SELECT * FROM sc WHERE cid='01') as t1,
    (SELECT * FROM sc WHERE cid='02') as t2 
WHERE t1.sid=t2.sid;

-- 1.2 查询存在" 01 "课程但可能不存在" 02 "课程的情况(不存在时显示为 null )
SELECT * FROM 
    (SELECT * FROM sc WHERE cid='01') as t1 
    LEFT JOIN 
    (SELECT * FROM sc WHERE cid='02') as t2
    ON t1.sid = t2.sid;

-- 1.3 查询不存在" 01 "课程但存在" 02 "课程的情况
SELECT  *
FROM sc
WHERE sc.sid not IN ( SELECT sid FROM sc WHERE cid='01') 
AND sc.cid = '02'; 



-- 2. 查询平均成绩大于等于 60 分的同学的学生编号和学生姓名和平均成绩
SELECT sname, avg_score, r.sid from student ,
(SELECT avg(score) as avg_score, sid from sc group by sid having avg(score)>=60)r
WHERE student.sid=r.sid;

SELECT sname, avg_score, r.sid from student JOIN 
(SELECT avg(score) as avg_score, sid from sc group by sid having avg(score)>=60)r
on student.sid=r.sid;

-- 3. 查询在 SC 表存在成绩的学生信息
SELECT * from student where student.sid in
(SELECT sid from sc) order by sid asc;

SELECT DISTINCT student.* from student, sc WHERE student.sid=sc.sid;

-- 4. 查询所有同学的学生编号、学生姓名、选课总数、所有课程的总成绩(没成绩的显示为 null )
SELECT sid, sname, classes, sum_score from student LEFT join 
(SELECT sid, count(cid) as classes, sum(score) as sum_score FROM sc group by sid )r
using (sid) ;

-- 5.