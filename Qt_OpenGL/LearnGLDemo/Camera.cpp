#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

Camera::~Camera()
{

}

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : m_vec3Front(glm::vec3(0.0f, 0.0f, -1.0f)),
      m_fMovementSpeed(SPEED),
      m_fMouseSensitivity(SENSITIVITY),
      m_fZoom(ZOOM)
{
    m_vec3Position = position;
    m_vec3WorldUp = up;
    m_fYaw = yaw;
    m_fPitch = pitch;
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
    : m_vec3Front(glm::vec3(0.0f, 0.0f, -1.0f)),
      m_fMovementSpeed(SPEED),
      m_fMouseSensitivity(SENSITIVITY),
      m_fZoom(ZOOM)
{
    m_vec3Position = glm::vec3(posX, posY, posZ);
    m_vec3WorldUp = glm::vec3(upX, upY, upZ);
    m_fYaw = yaw;
    m_fPitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(m_vec3Position, m_vec3Position + m_vec3Front, m_vec3Up);
}

void Camera::ProcessKeyboard(CameraMovement direction, float deltaTime)
{
    float velocity = m_fMovementSpeed * deltaTime;
    if (direction == FORWARD)
        m_vec3Position += m_vec3Front * velocity;
    if (direction == BACKWARD)
        m_vec3Position -= m_vec3Front * velocity;
    if (direction == LEFT)
        m_vec3Position -= m_vec3Right * velocity;
    if (direction == RIGHT)
        m_vec3Position += m_vec3Right * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
    xoffset *= m_fMouseSensitivity;
    yoffset *= m_fMouseSensitivity;

    m_fYaw   += xoffset;
    m_fPitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (m_fPitch > 89.0f)
            m_fPitch = 89.0f;
        if (m_fPitch < -89.0f)
            m_fPitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    m_fZoom -= (float)yoffset;
    if (m_fZoom < 1.0f)
        m_fZoom = 1.0f;
    if (m_fZoom > 45.0f)
        m_fZoom = 45.0f;
}

void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
    front.y = sin(glm::radians(m_fPitch));
    front.z = sin(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
    m_vec3Front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    m_vec3Right = glm::normalize(glm::cross(m_vec3Front, m_vec3WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_vec3Up    = glm::normalize(glm::cross(m_vec3Right, m_vec3Front));
}
