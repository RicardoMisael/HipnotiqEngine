#pragma once
#include "Prerequisites.h"
#include "InputLayout.h"

class Device;
class DeviceContext;

class 
ShaderProgram {
public:
  ShaderProgram() = default;
  ~ShaderProgram() = default;

  /**
   * @brief Inicializa y configura el programa de sombreado.
   * @param device Referencia al dispositivo.
   * @param fileName Nombre del archivo de sombreado.
   * @param Layout Vector que contiene la descripci�n del dise�o de entrada.
   * @return Resultado de la operaci�n (HRESULT).
   */
  HRESULT
  init(Device& device,
      const std::string& fileName,
      std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

  /**
   * @brief Actualiza el shader program.
   */
  void
  update();

  /**
   * @brief Establece el dise�o de entrada, el sombreador de v�rtices y el sombreador de p�xeles en el contexto del dispositivo.
   * @param deviceContext Referencia al contexto del dispositivo.
   */
  void
  render(DeviceContext& DeviceContext);

  /**
   * @brief Libera recursos
   */
  void
  destroy();

  /**
   * @brief Crea el input layout utilizando el dispositivo y la descripci�n del dise�o de entrada proporcionados.
   * @param device Referencia al dispositivo.
   * @param Layout Vector que contiene la descripci�n del dise�o de entrada.
   * @return Resultado de la operaci�n (HRESULT).
   */
  HRESULT
  CreateInputLayout(Device& device, std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

  /**
   * @brief Crea un shader de v�rtices o de p�xeles seg�n el tipo especificado.
   * @param device Referencia al dispositivo.
   * @param type Tipo de sombreador a crear (v�rtices o p�xeles).
   * @return Resultado de la operaci�n (HRESULT).
   */
  HRESULT
  CreateShader(Device& device, ShaderType type);

  /**
   * @brief Lee y compila un archivo de sombreado utilizando el punto de entrada y el modelo de sombreado especificados.
   * @param szFileName Nombre del archivo de sombreado.
   * @param szEntryPoint Funci�n de punto de entrada en el sombreador.
   * @param szShaderModel Modelo de sombreado a utilizar.
   * @param ppBlobOut Puntero de salida a los datos del sombreador compilado.
   * @return Resultado de la operaci�n (HRESULT).
   */
  HRESULT
  CompileShaderFromFile(char* szFileName,
                        LPCSTR szEntryPoint,
                        LPCSTR szShaderModel,
                        ID3DBlob** ppBlobOut);

  ID3D11VertexShader* m_VertexShader = nullptr;
  ID3D11PixelShader* m_PixelShader = nullptr;
  InputLayout m_inputLayout;

private:
  std::string m_shaderFileName;
  ID3DBlob* m_vertexShaderData = nullptr;
  ID3DBlob* m_pixelShaderData = nullptr;
};