--#5
-- 1. Книги автора
SELECT * FROM books WHERE author_id = 1;

-- 2. Книги по жанру  
SELECT * FROM books WHERE genre = 'Роман';

-- 3. Пользователи по дате
SELECT * FROM users WHERE registration_date > '2024-01-01';

-- 4. Не возвращенные книги
SELECT * FROM borrowed_books WHERE return_date IS NULL;