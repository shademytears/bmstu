--#6
--SELECT user_id, COUNT(*) FROM borrowed_books GROUP BY user_id;
--UPDATE users SET name = 'Новое имя' WHERE id = 1;
DELETE FROM borrowed_books WHERE user_id = 1;
DELETE FROM users WHERE id = 1;