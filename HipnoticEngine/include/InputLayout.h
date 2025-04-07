#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

class 
InputLayout {
public:
  InputLayout() = default;
  ~InputLayout() = default;

  /**
   * @brief Configura el dise�o de entrada utilizando el dispositivo, 
   * la descripci�n del dise�o de entrada y los datos del sombreador de v�rtices.
   * @param device Referencia al dispositivo utilizado para crear el dise�o de entrada.
   * @param Layout Vector de estructuras D3D11_INPUT_ELEMENT_DESC que describen el dise�o de entrada.
   * @param VertexShaderData Puntero a los datos del sombreador de v�rtices.
   * @return Resultado de la operaci�n (HRESULT).
   */
  HRESULT
  init(Device& device,
      std::vector<D3D11_INPUT_ELEMENT_DESC>& Layout,
      ID3DBlob* VertexShaderData);

  /**
   * @brief Actualiza el estado del dise�o de entrada para reflejar modificaciones en tiempo de ejecuci�n.
   */
  void
  update();

  /**
   * @brief Vincula el dise�o de entrada al pipeline de renderizado.
   * @param deviceContext Referencia al contexto del dispositivo.
   */
  void
  render(DeviceContext& deviceContext);

  /**
   * @brief Libera recrusos
   */
  void
  destroy();

public:
  ID3D11InputLayout* m_inputLayout = nullptr;
};