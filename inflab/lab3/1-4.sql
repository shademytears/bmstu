DROP TABLE IF EXISTS borrowed_books;
DROP TABLE IF EXISTS books;
DROP TABLE IF EXISTS users;
DROP TABLE IF EXISTS authors;
--#1 #2
CREATE TABLE authors(
	id INT PRIMARY KEY,
	name VARCHAR(255),
	birth_year INT
);
CREATE TABLE books(
	id INT PRIMARY KEY,
	title VARCHAR(255),
	author_id INT,
	publication_year INT, 
	genre VARCHAR(255),
	FOREIGN KEY (author_id) REFERENCES authors(id)
);
CREATE TABLE users(
	id INT PRIMARY KEY,
	name VARCHAR(255),
	registration_date DATE
);
CREATE TABLE borrowed_books(
	user_id INT,
	book_id INT,
	borrow_date DATE,
	return_date DATE,
	PRIMARY KEY (user_id, book_id, borrow_date),
	FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (book_id) REFERENCES books(id)
);

--#3
-- Авторы
INSERT INTO authors (id, name, birth_year) VALUES
(1, 'Лев Толстой', 1828),
(2, 'Фёдор Достоевский', 1821),
(3, 'Антон Чехов', 1860);

-- Книги
INSERT INTO books (id, title, author_id, publication_year, genre) VALUES
(1, 'Война и мир', 1, 1869, 'Роман-эпопея'),
(2, 'Преступление и наказание', 2, 1866, 'Роман'),
(3, 'Вишнёвый сад', 3, 1904, 'Пьеса');

-- Пользователи
INSERT INTO users (id, name, registration_date) VALUES
(1, 'Иван Петров', '2024-01-15'),
(2, 'Мария Сидорова', '2024-02-20'),
(3, 'Алексей Козлов', '2024-03-10');

-- Взятые книги (ВСЕ комбинации УНИКАЛЬНЫЕ)
INSERT INTO borrowed_books (user_id, book_id, borrow_date, return_date) VALUES
(1, 1, '2024-05-01', '2024-05-15'),   -- Иван взял Войну и мир
(2, 2, '2024-05-05', '2024-05-20'),   -- Мария взяла Преступление и наказание
(3, 3, '2024-05-10', NULL),           -- Алексей взял Вишнёвый сад (не вернул)
(1, 2, '2024-05-15', '2024-05-30');   -- Иван взял Преступление и наказание



--#4
-- 1. Книги автора
SELECT books.*, authors.name as author_name FROM books 
JOIN authors ON books.author_id = authors.id 
WHERE author_id = 1;

-- 2. Книги по жанру  
SELECT * FROM books WHERE genre = 'Роман';

-- 3. Пользователи по дате
SELECT * FROM users WHERE registration_date > '2024-01-01';

-- 4. Не возвращенные книги
SELECT * FROM borrowed_books WHERE return_date IS NULL;
