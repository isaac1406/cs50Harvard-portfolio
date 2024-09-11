--
SELECT description FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2023;

SELECT transcript FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023;

SELECT name, phone_number
FROM people
WHERE license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 7
    AND year = 2023
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
)
AND phone_number IN
(
    SELECT caller
    FROM phone_calls
    WHERE day = 28
    AND month = 7
    AND year = 2023
    AND duration < 60
)
AND people.id IN
(
    SELECT person_id FROM bank_accounts
    JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
    WHERE day = 28
    AND month = 7
    AND year = 2023
    AND transaction_type = 'withdraw'
    AND atm_location = 'Leggett Street'
);

SELECT receiver
FROM phone_calls
WHERE day = 28
AND month = 7
AND year = 2023
AND duration < 60
AND caller IN
(
    SELECT phone_number FROM people
    WHERE license_plate IN
    (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE day = 28
        AND month = 7
        AND year = 2023
        AND hour = 10
        AND minute >= 15
        AND minute <= 25
    )
    AND people.id IN
    (
        SELECT person_id FROM bank_accounts
        JOIN atm_transactions
        ON bank_accounts.account_number = atm_transactions.account_number
        WHERE day = 28
        AND month = 7
        AND year = 2023
        AND transaction_type = 'withdraw'
        AND atm_location = 'Leggett Street'
    )
);

SELECT name, passport_number FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE day = 28
AND month = 7
AND year = 2023
AND duration < 60
AND caller IN
(
    SELECT phone_number FROM people
    WHERE license_plate IN
    (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE day = 28
        AND month = 7
        AND year = 2023
        AND hour = 10
        AND minute >= 15
        AND minute <= 25
    )
    AND people.id IN
    (
        SELECT person_id FROM bank_accounts
        JOIN atm_transactions
        ON bank_accounts.account_number = atm_transactions.account_number
        WHERE day = 28
        AND month = 7
        AND year = 2023
        AND transaction_type = 'withdraw'
        AND atm_location = 'Leggett Street'
    )
);



SELECT flight_id, passport_number FROM passengers
JOIN flights ON id = flight_id
WHERE flights.day = 29
AND flights.month = 7
AND flights.year = 2023
AND passengers.passport_number IN
(
    SELECT passport_number FROM people
    JOIN phone_calls
    ON people.phone_number = phone_calls.caller
    WHERE phone_calls.day = 28
    AND phone_calls.month = 7
    AND phone_calls.year = 2023
    AND phone_calls.duration < 60
    AND phone_calls.caller IN
    (
        SELECT phone_number FROM people
        WHERE license_plate IN
        (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE day = 28
            AND month = 7
            AND year = 2023
            AND hour = 10
            AND minute >= 15
            AND minute <= 25
        )
        AND people.id IN
        (
            SELECT person_id FROM bank_accounts
            JOIN atm_transactions
            ON bank_accounts.account_number = atm_transactions.account_number
            WHERE day = 28
            AND month = 7
            AND year = 2023
            AND transaction_type = 'withdraw'
            AND atm_location = 'Leggett Street'
        )
    )
)
ORDER BY flights.hour ASC
LIMIT 1;

SELECT city FROM airports
JOIN flights
ON airports.id = flights.destination_airport_id
WHERE flights.id =
(
    SELECT flight_id FROM passengers
    JOIN flights ON id = flight_id
    WHERE flights.day = 29
    AND flights.month = 7
    AND flights.year = 2023
    AND passengers.passport_number IN
    (
        SELECT passport_number FROM people
        JOIN phone_calls
        ON people.phone_number = phone_calls.caller
        WHERE phone_calls.day = 28
        AND phone_calls.month = 7
        AND phone_calls.year = 2023
        AND phone_calls.duration < 60
        AND phone_calls.caller IN
        (
            SELECT phone_number FROM people
            WHERE license_plate IN
            (
                SELECT license_plate
                FROM bakery_security_logs
                WHERE day = 28
                AND month = 7
                AND year = 2023
                AND hour = 10
                AND minute >= 15
                AND minute <= 25
            )
            AND people.id IN
            (
                SELECT person_id FROM bank_accounts
                JOIN atm_transactions
                ON bank_accounts.account_number = atm_transactions.account_number
                WHERE day = 28
                AND month = 7
                AND year = 2023
                AND transaction_type = 'withdraw'
                AND atm_location = 'Leggett Street'
            )
        )
    )
    ORDER BY flights.hour ASC
    LIMIT 1
);


SELECT name FROM people
WHERE passport_number =
(
    SELECT passport_number FROM passengers
    JOIN flights ON id = flight_id
    WHERE flights.day = 29
    AND flights.month = 7
    AND flights.year = 2023
    AND passengers.passport_number IN
    (
        SELECT passport_number FROM people
        JOIN phone_calls
        ON people.phone_number = phone_calls.caller
        WHERE phone_calls.day = 28
        AND phone_calls.month = 7
        AND phone_calls.year = 2023
        AND phone_calls.duration < 60
        AND phone_calls.caller IN
        (
            SELECT phone_number FROM people
            WHERE license_plate IN
            (
                SELECT license_plate
                FROM bakery_security_logs
                WHERE day = 28
                AND month = 7
                AND year = 2023
                AND hour = 10
                AND minute >= 15
                AND minute <= 25
            )
            AND people.id IN
            (
                SELECT person_id FROM bank_accounts
                JOIN atm_transactions
                ON bank_accounts.account_number = atm_transactions.account_number
                WHERE day = 28
                AND month = 7
                AND year = 2023
                AND transaction_type = 'withdraw'
                AND atm_location = 'Leggett Street'
            )
        )
    )
    ORDER BY flights.hour ASC
    LIMIT 1
);



