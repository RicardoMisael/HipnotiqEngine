#pragma once
#include "Prerequisites.h"
#include "ECS/Transform.h"
#include "ECS/Actor.h"


class Window;
class Device;
class DeviceContext;

class
UserInterface {
public:
  UserInterface() = default;
  ~UserInterface() = default;

  /**
   * @brief Inicializa los elementos de la interfaz de usuario.
   * @param window Puntero a la ventana en la que se mostrar� la interfaz.
   * @param device Dispositivo gr�fico utilizado para la renderizaci�n.
   * @param deviceContext Contexto del dispositivo para las operaciones gr�ficas.
   */
  void
  init(void* window,
       ID3D11Device* device,
       ID3D11DeviceContext* deviceContext);

  /**
   * @brief Actualiza el estado de la interfaz de usuario.
   */
  void
  update();

  /**
   * @brief Renderiza la interfaz de usuario en la ventana.
   */
  void
  render();

  /**
   * @brief Libera los recursos
   */
  void
  destroy();

  /**
   * @brief A�ade un estilo basado en Natanael Cano
   */
  void
  NataStyle();

  /**
   * @brief M�todo que muestra la jerarqu�a con todos los actores del vector de actores
   */
  void
  hierarchy(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

  /**
   * @brief Permite mostrar y modificar el transform de todos los actores de la jerarqu�a
   */
  void
  inspector(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

private:
  EngineUtilities::TSharedPointer<Actor> selectedActor;
};