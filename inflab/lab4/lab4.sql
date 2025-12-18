-- Удаляем все таблицы
DROP TABLE IF EXISTS borrowed_books CASCADE;
DROP TABLE IF EXISTS books CASCADE;
DROP TABLE IF EXISTS users CASCADE;
DROP TABLE IF EXISTS authors CASCADE;

-- Создаем заново
CREATE TABLE authors (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    birth_year INT
);

CREATE TABLE books (
    id SERIAL PRIMARY KEY,
    title VARCHAR(200),
    author_id INT REFERENCES authors(id),
    publication_year INT,
    genre VARCHAR(50)
);

CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    registration_date DATE DEFAULT CURRENT_DATE
);

CREATE TABLE borrowed_books (
    id SERIAL PRIMARY KEY,
    user_id INT REFERENCES users(id),
    book_id INT REFERENCES books(id),
    borrow_date DATE DEFAULT CURRENT_DATE,
    return_date DATE
);