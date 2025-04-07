#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

class
SamplerState {
public:
  SamplerState() = default;
  ~SamplerState() = default;

  /**
   * @brief Inicializa el SamplerState, definiendo c�mo se muestrean las texturas.
 * @param device Referencia al dispositivo gr�fico.
 * @return HRESULT indicando �xito o error en la inicializaci�n.
   */
  HRESULT
  init(Device& device);

  /**
   * @brief Actualiza la configuraci�n del SamplerState.
   */
  void
  update();

  /**
   * @brief Vincula el SamplerState al contexto del dispositivo para el muestreo de texturas.
   * @param deviceContext Contexto del dispositivo.
   * @param StartSlot Primer slot donde se vincular� el SamplerState.
   * @param numSamplers N�mero de estados de muestreo a establecer.
   */
  void
  render(DeviceContext& deviceContext, 
           unsigned int StartSlot, 
           unsigned int numSamplers);

  /**
   * @brief Libera los recursos
   */
  void
  destroy();

private:
  ID3D11SamplerState* m_samplerState = nullptr;
};