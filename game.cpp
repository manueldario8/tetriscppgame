#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
#include "board.h"


using namespace sf;
using namespace std;

void Game::IniciarJuego()
{
    RenderWindow window(VideoMode({ 800, 600 }), "Tetris");

    RectangleShape bloque(Vector2f(30.f, 30.f));
    bloque.setFillColor(Color::Red);

    Clock movClock;
    Clock gravedad;

    bool holdA = false, holdD = false, holdS = false, holdW = false;
    float nextMoveTime = 0.f;

    Pieza PiezaT(TipoPieza::L, 7, 1);
    auto bloquesT = PiezaT.GetBloques();

    while (window.isOpen()) {

        while (const optional<Event> event = window.pollEvent()) {

            if (event->is<Event::Closed>()) {
                window.close();
            }

            if (const auto* kp = event->getIf<Event::KeyPressed>()) {

                switch (kp->code) {

                case Keyboard::Key::Space:
                    PiezaT.Rotar();
                    bloquesT = PiezaT.GetBloques();
                    break;

                case Keyboard::Key::A:
                    holdA = true;
                    if (tablero.PuedoMover(bloquesT, -1, 0)) {
                        PiezaT.Mover(-1, 0);
                        bloquesT = PiezaT.GetBloques();
                        movClock.restart();
                        nextMoveTime = MOVE_INITIAL_DELAY;
                    }
                    break;

                case Keyboard::Key::D:
                    holdD = true;
                    if (tablero.PuedoMover(bloquesT, 1, 0)) {
                        PiezaT.Mover(1, 0);
                        bloquesT = PiezaT.GetBloques();
                        movClock.restart();
                        nextMoveTime = MOVE_INITIAL_DELAY;
                    }
                    break;

                case Keyboard::Key::W:
                    holdW = true;
                    if (tablero.PuedoMover(bloquesT, 0, -1)) {
                        PiezaT.Mover(0, -1);
                        bloquesT = PiezaT.GetBloques();
                        movClock.restart();
                        nextMoveTime = MOVE_INITIAL_DELAY;
                    }
                    break;

                case Keyboard::Key::S:
                    holdS = true;
                    if (tablero.PuedoMover(bloquesT, 0, 1)) {
                        PiezaT.Mover(0, 1);
                        bloquesT = PiezaT.GetBloques();
                        movClock.restart();
                        nextMoveTime = MOVE_INITIAL_DELAY;
                    }
                    break;

                default:
                    break;
                }
            }

            if (const auto* kr = event->getIf<Event::KeyReleased>()) {

                switch (kr->code) {
                case Keyboard::Key::A: holdA = false; break;
                case Keyboard::Key::D: holdD = false; break;
                case Keyboard::Key::W: holdW = false; break;
                case Keyboard::Key::S: holdS = false; break;
                default: break;
                }
            }
        }

        float elapsed = movClock.getElapsedTime().asSeconds();
        float elapsedGravedad = gravedad.getElapsedTime().asSeconds();

        if (elapsedGravedad >= GRAVEDAD_DELAY) {

            if (tablero.PuedoMover(bloquesT, 0, 1)) {
                PiezaT.Mover(0, 1);
                bloquesT = PiezaT.GetBloques();
            }

            gravedad.restart();
        }

        if (elapsed >= nextMoveTime) {

            bool moved = false;

            if (holdA && tablero.PuedoMover(bloquesT, -1, 0)) {
                PiezaT.Mover(-1, 0);
                moved = true;
            }

            if (holdD && tablero.PuedoMover(bloquesT, 1, 0)) {
                PiezaT.Mover(1, 0);
                moved = true;
            }

            if (holdW && tablero.PuedoMover(bloquesT, 0, -1)) {
                PiezaT.Mover(0, -1);
                moved = true;
            }

            if (holdS && tablero.PuedoMover(bloquesT, 0, 1)) {
                PiezaT.Mover(0, 1);
                moved = true;
            }

            if (moved) {
                bloquesT = PiezaT.GetBloques();
                movClock.restart();
                nextMoveTime = MOVE_REPEAT_DELAY;
            }
        }



        window.clear();

        for (int i = 0; i < 4; i++) {
            bloque.setPosition(Vector2f(bloquesT[i].x * 32.f, bloquesT[i].y * 32.f));
            window.draw(bloque);
        }

        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 20; y++) {

                if (tablero.GetCasilla(x, y) == 1) {
                    bloque.setPosition(Vector2f(x * 32.f, y * 32.f));
                    window.draw(bloque);
                }
            }
        }

        window.display();
    }
}
