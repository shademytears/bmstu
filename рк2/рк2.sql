DROP TABLE IF EXISTS notes CASCADE;
DROP TABLE IF EXISTS attendance CASCADE;
DROP TABLE IF EXISTS grades CASCADE;
DROP TABLE IF EXISTS students CASCADE;
DROP TABLE IF EXISTS subjects CASCADE;

CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(20) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INTEGER NOT NULL,
    subject_id INTEGER NOT NULL,
    grade INTEGER
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INTEGER NOT NULL,
    date_attended DATE NOT NULL,
    status VARCHAR(20) NOT NULL
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INTEGER NOT NULL,
    note_text TEXT NOT NULL
);

INSERT INTO students (full_name, group_number) VALUES
('Иванов Иван Иванович', 'ГР-01'),
('Петров Петр Петрович', 'ГР-01'),
('Сидорова Анна Сергеевна', 'ГР-01'),
('Козлов Алексей Владимирович', 'ГР-01'),
('Смирнова Екатерина Дмитриевна', 'ГР-01'),
('Васильев Дмитрий Андреевич', 'ГР-01');

INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

INSERT INTO grades (student_id, subject_id, grade) VALUES
(1, 1, 5), (1, 2, 4), (1, 3, 5),
(2, 1, 3), (2, 2, 4), (2, 3, 4),
(3, 1, 5), (3, 2, 5), (3, 3, 5),
(4, 1, 3), (4, 2, 4), (4, 3, 3),
(5, 1, 4), (5, 2, 4), (5, 3, 5),
(6, 1, 5), (6, 2, 4), (6, 3, 4);

INSERT INTO attendance (student_id, date_attended, status) VALUES
(1, '2024-03-20', 'присутствовал'),
(2, '2024-03-20', 'присутствовал'),
(3, '2024-03-20', 'присутствовал'),
(4, '2024-03-20', 'отсутствовал'),
(5, '2024-03-20', 'присутствовал'),
(6, '2024-03-20', 'присутствовал'),
(1, '2024-03-21', 'присутствовал'),
(2, '2024-03-21', 'отсутствовал'),
(3, '2024-03-21', 'присутствовал'),
(4, '2024-03-21', 'присутствовал'),
(5, '2024-03-21', 'присутствовал'),
(6, '2024-03-21', 'присутствовал');

INSERT INTO notes (student_id, note_text) VALUES
(1, 'Отличник по всем предметам'),
(2, 'Нужна помощь по информатике'),
(3, 'Хорошо работает в команде'),
(4, 'Редко посещает занятия по информатике'),
(5, 'Прогресс по информатике'),
(6, 'Любит информатику');

CREATE INDEX idx_students_group ON students(group_number);

CREATE INDEX idx_grades_student ON grades(student_id);

CREATE INDEX idx_notes_text_gin ON notes USING gin(to_tsvector('russian', note_text));

CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    s.group_number,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name, s.group_number;

BEGIN TRANSACTION;

INSERT INTO students (full_name, group_number) 
VALUES ('Новенкий Станислав Олегович', 'ГР-01');

INSERT INTO grades (student_id, subject_id, grade) VALUES 
(7, 1, 4), 
(7, 2, 3), 
(7, 3, 5); 

COMMIT;

WITH numbered_students AS (
    SELECT 
        student_id,
        full_name,
        group_number,
        ROW_NUMBER() OVER (ORDER BY student_id) as row_num
    FROM students 
    WHERE group_number = 'ГР-01'
)
SELECT 
    student_id,
    full_name,
    group_number
FROM numbered_students
WHERE row_num BETWEEN 
    (SELECT row_num FROM numbered_students WHERE student_id = 3) - 2 
    AND 
    (SELECT row_num FROM numbered_students WHERE student_id = 3) + 3
    AND student_id != 3
ORDER BY row_num
LIMIT 5;

SELECT * FROM student_avg_grades WHERE student_id = 3;

SELECT 
    s.subject_name,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade,
    COUNT(g.grade_id) as total_grades
FROM subjects s
JOIN grades g ON s.subject_id = g.subject_id
WHERE s.subject_name = 'Информатика'
GROUP BY s.subject_id, s.subject_name;

SELECT 
    n.note_id,
    s.full_name,
    n.note_text
FROM notes n
JOIN students s ON n.student_id = s.student_id
WHERE to_tsvector('russian', n.note_text) @@ to_tsquery('russian', 'информатика');

BEGIN TRANSACTION;

SELECT * FROM attendance 
WHERE student_id = 4 AND date_attended = '2024-03-20';

UPDATE attendance 
SET status = 'присутствовал'
WHERE student_id = 4 AND date_attended = '2024-03-20';

SELECT * FROM attendance 
WHERE student_id = 4 AND date_attended = '2024-03-20';

COMMIT;

SELECT * FROM students;

SELECT * FROM subjects;

SELECT * FROM grades;

SELECT * FROM attendance;

SELECT * FROM notes;
