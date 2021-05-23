# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 12:29:43 by kyekim            #+#    #+#              #
#    Updated: 2021/05/23 11:42:28 by kyekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS = sources/minirt.c\
	   sources/etc/wrapper.c\
	   sources/etc/scene.c\
	   sources/etc/get_next_line.c\
	   sources/input/key.c\
	   sources/input/mouse.c\
	   sources/input/parser.c\
	   sources/input/get.c\
	   sources/input/set.c\
	   sources/input/is.c\
	   sources/input/number.c\
	   sources/input/mesh.c\
	   sources/input/stage.c\
	   sources/output/screen.c\
	   sources/output/color.c\
	   sources/output/bmp.c\
	   sources/output/window.c\
	   sources/output/raw.c\
	   sources/output/record.c\
	   sources/output/save.c\
	   sources/world/hittable.c\
	   sources/world/ray.c\
	   sources/world/object.c\
	   sources/world/camera.c\
	   sources/world/material/material.c\
	   sources/world/material/lambertian.c\
	   sources/world/material/metal.c\
	   sources/world/material/dielectric.c\
	   sources/world/material/emissive.c\
	   sources/geometry/sphere.c\
	   sources/geometry/rectangle.c\
	   sources/geometry/plane.c\
	   sources/geometry/triangle.c\
	   sources/geometry/circle.c\
	   sources/geometry/cylinder.c\
	   sources/geometry/spot.c\
	   sources/math/random_float.c\
	   sources/math/random_vector.c\
	   sources/math/vector.c\
	   sources/math/vector_util.c\
	   sources/math/vector_arithmetic.c\
	   sources/math/vector_calculation.c\
	   sources/math/rotation.c\
	   sources/math/util.c

BONUSSRCS = sources/output/record_bonus.c\
			sources/world/ray_bonus.c\
		 	sources/geometry/box_bonus.c\
		 	sources/geometry/pyramid_bonus.c\
		 	sources/input/mesh_bonus.c\
		 	sources/input/parser_bonus.c

HEADER = sources/minirt.h\
		 sources/etc/typedef.h\
		 sources/math/vector.h\
		 sources/math/random.h\
		 sources/input/input.h

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
BONUSFLAG = -D BONUS
			#-D RAINBOW

RM = rm -f
LIBX = minilibx
DLIBX = libmlx.dylib

all: $(NAME)

$(NAME): $(SRCS) $(DLIBX) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L. -lmlx

$(DLIBX):
	$(MAKE) -C $(LIBX)
	mv $(LIBX)/$(DLIBX) .

clean:
	$(MAKE) clean -C $(LIBX)
	$(RM) $(DLIBX)
	$(RM) *.o 

fclean: clean
	$(RM) $(NAME) $(DLIBX) img.bmp

re: fclean all

bonus: SRCS += $(BONUSSRCS)
bonus: CFLAGS += $(BONUSFLAG)
bonus: all

.PHONY: all clean fclean re bonus
.SILENT: clean
